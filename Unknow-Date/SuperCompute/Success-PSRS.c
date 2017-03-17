//This version requires DATA_NUM/process_num is an int 
#define DATA_NUM 18
#define NUM_PRINT_A_LINE 6
#include <mpi.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unistd.h>
#include "multimerge.h"
using namespace std;
void PrintArray(int* p_array,int size,int num_print_a_line)
{
	if(p_array != NULL)
	{
		for(int i = 0;i < size;i++)
	{
		cout << p_array[i] << '\t';
		if((i+1) % num_print_a_line == 0 && i != 0)
		{
			cout << endl;
		}
	}
	}
	else
	{
		cout <<"NULL"<<endl;
	}
	if(size % num_print_a_line != 0)
	{
		cout <<endl;
	}
}
void CheckArrayContain(int* p_g_raw_data, int* p_local_data,int per_process_data_num,int pid, int num_print_a_line)
{
	num_print_a_line = NUM_PRINT_A_LINE;
	if(pid == 0)
	{
		cout << "PRINTING MAIN ARRAY" <<endl;
		PrintArray(p_g_raw_data,DATA_NUM,num_print_a_line);		
	}
	//cout << "PROCESS " << pid << " IS PRINTING ITS ARRAY" <<endl;
	//PrintArray(p_local_data,per_process_data_num,num_print_a_line);
}
int CompareInts (const void * a, const void * b)
{
  if ( *(int*)a <  *(int*)b ) return -1;
  if ( *(int*)a == *(int*)b ) return 0;
  if ( *(int*)a >  *(int*)b ) return 1;
}
int main()
{
	//initial
	int pid,process_num;
	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD,&pid);
	MPI_Comm_size(MPI_COMM_WORLD,&process_num);
	int* p_local_regular_samples = new int[process_num];
	int per_process_data_num=DATA_NUM/process_num;
	int *p_local_data=new int [per_process_data_num];
	srand(time(0));
	int* p_g_raw_data = new int[DATA_NUM];
	/*for(int j=0;j<DATA_NUM;j++)
		{
			p_g_raw_data[j]=rand()%50; //golbal array	
		}*/
	p_g_raw_data[0]=48;
	p_g_raw_data[1]=39;
	p_g_raw_data[2]=6;
	p_g_raw_data[3]=72;
	p_g_raw_data[4]=91;
	p_g_raw_data[5]=14;
	p_g_raw_data[6]=69;
	p_g_raw_data[7]=40;
	p_g_raw_data[8]=89;
	p_g_raw_data[9]=61;
	p_g_raw_data[10]=12;
	p_g_raw_data[11]=21;
	p_g_raw_data[12]=84;
	p_g_raw_data[13]=58;
	p_g_raw_data[14]=32;
	p_g_raw_data[15]=33;
	p_g_raw_data[16]=72;
	p_g_raw_data[17]=20;
	int* p_g_regular_samples = new int[process_num*process_num];
	//scatter to each process and local sort
	MPI_Scatter(p_g_raw_data,per_process_data_num,MPI_INT,p_local_data,per_process_data_num,MPI_INT,0,MPI_COMM_WORLD);
	qsort(p_local_data,per_process_data_num,sizeof(int),CompareInts);
	//get regular samples
	//********************************************
	//UNUSED TEST CODE
	//CheckArrayContain(p_g_raw_data,p_local_data,per_process_data_num,pid,6);
	//********************************************
	for(int i = 0;i< process_num;i++)
	{
		p_local_regular_samples[i] = p_local_data[i*per_process_data_num/process_num];
	}
	MPI_Gather(p_local_regular_samples,process_num,MPI_INT,p_g_regular_samples,process_num,MPI_INT,0,MPI_COMM_WORLD);
	//get privots
	int pivots[process_num-1];
	if (pid == 0)
	{
		// multimerge the numproc sorted lists into one
		int *starts[process_num];  // array of lists
		int lengths[process_num];  // array of lengths of lists
		for(int i=0;i<process_num;i++)
		{
			starts[i]=&p_g_regular_samples[i*process_num];
			lengths[i]=process_num;
		}
		int p_g_sorted_regular_samples[process_num*process_num];  // merged list
		multimerge(starts,lengths,process_num,p_g_sorted_regular_samples,process_num*process_num);
		// regularly select process_num-1 of pivot candidates to broadcast
		// as partition pivot values for myData
		for(int i=0; i<process_num-1; i++)
		{
			pivots[i] = p_g_sorted_regular_samples[(i+1)*process_num];
		}
	}
	MPI_Bcast(pivots,process_num-1,MPI_INT,0,MPI_COMM_WORLD);
	//Partition
	int start_position_partition[process_num];
	start_position_partition[0]=0;
	//TO DO:Think when all elements are same
	for(int j=0;j<(process_num-1);j++)
	{
		for(int i=0;i<per_process_data_num;i++)
		{
			if(pivots[j]<p_local_data[i])
			{
				start_position_partition[j+1]=i;
				break;
			}		
		}
	}
	//cout << "I am process "<<pid<<"I got start_position_partition"<<endl;
	//cout <<start_position_partition[0]<<'\t'<<start_position_partition[1]<<'\t'<<start_position_partition[2]<<endl;
	int length_partition[process_num];
	for(int i=0;i<process_num;i++)
	{
		if(i==process_num-1)
		{
			length_partition[i]=per_process_data_num-start_position_partition[i];
		}
		else
		{
			length_partition[i]=start_position_partition[i+1]-start_position_partition[i];
		}
	}
	/*
	if(pid==0)
	{
		length_partition[0]=2;
		length_partition[1]=2;
		length_partition[2]=2;
	}
	if(pid==1)
	{
		length_partition[0]=2;
		length_partition[1]=3;
		length_partition[2]=1;		
	}
	if(pid==2)
	{
		length_partition[0]=3;
		length_partition[1]=1;
		length_partition[2]=2;		
	}*/
	//All - compatible
	int length_re_assigned_partition[process_num];
	MPI_Alltoall(length_partition,1,MPI_INT,length_re_assigned_partition,1,MPI_INT,MPI_COMM_WORLD);
	int length_re_assigned_array=0;
	int start_position_re_partition[process_num];
	start_position_re_partition[0]=0;
	for(int i=0;i<process_num;i++)
	{
		length_re_assigned_array+=length_re_assigned_partition[i];
	}
	for(int i=1;i<process_num;i++)
	{
		start_position_re_partition[i]=start_position_re_partition[i-1]+length_re_assigned_partition[i-1];
	}	
	int* p_re_assigned_array= new int[length_re_assigned_array];
	MPI_Alltoallv(p_local_data,length_partition,start_position_partition,MPI_INT,p_re_assigned_array,length_re_assigned_partition,start_position_re_partition,MPI_INT,MPI_COMM_WORLD);
	//Final merged partitions
	qsort(p_re_assigned_array,length_re_assigned_array,sizeof(int),CompareInts);
	//Final merged partitions
	int* p_send_length_re_assigned_sorted_array =new int[process_num];
	MPI_Gather(&length_re_assigned_array,1,MPI_INT,p_send_length_re_assigned_sorted_array,1,MPI_INT,0,MPI_COMM_WORLD);
	int* start_position_sorted_array=new int[process_num];
	start_position_sorted_array[0]=0;
	for(int i=1;i<process_num;i++)
	{
		start_position_sorted_array[i]=start_position_sorted_array[i-1]+p_send_length_re_assigned_sorted_array[i-1];
	}	
	MPI_Gatherv(p_re_assigned_array,length_re_assigned_array,MPI_INT,p_g_raw_data,p_send_length_re_assigned_sorted_array,start_position_sorted_array,MPI_INT,0,MPI_COMM_WORLD);
	CheckArrayContain(p_g_raw_data,NULL,per_process_data_num,pid,NUM_PRINT_A_LINE);
	//**************************************************
	//UNUSED TEST CODE
	//cout << "I am process "<<pid<<"I got length_re_assigned_partition"<<endl;
	//cout <<length_re_assigned_partition[0]<<'\t'<<length_re_assigned_partition[1]<<'\t'<<length_re_assigned_partition[2]<<endl;
	/*for(int i =0;i<process_num;i++)
		{
			cout<<"I am pid "<<pid<<" " ;
			cout<<p_local_regular_samples[i]<<'\t' <<endl;
		}
	cout <<"I "<<pid<<" run here!"<<endl;*/
/*	if(pid == 0)
	{
		for(int i =0;i<process_num*process_num;i++)
		{
			cout <<"!!!!!!!OK"<<i<<"!!!!!!!";
			cout << p_g_regular_samples[i]<<'\t';
		}
	}*/
	//sleep(1);
	//**************************************************
	delete[] p_local_data;
	delete[] p_local_regular_samples;
	delete[] p_g_raw_data;
	delete[] p_g_regular_samples;
	delete[] p_re_assigned_array;
	delete[] p_send_length_re_assigned_sorted_array;
	MPI_Finalize();
	return 0;
}

