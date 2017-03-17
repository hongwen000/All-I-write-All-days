#define NUM_PRINT_A_LINE 10
#include <mpi.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <iomanip>
using namespace std;
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
	double start_time = 0.0, end_time;
	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD,&pid);
	MPI_Comm_size(MPI_COMM_WORLD,&process_num);
	int DATA_NUM;
	if(pid == 0)
	{
	cout << "INPUT DATA NUMBER"<<endl;
	cin >> DATA_NUM;
	srand(time(0));
	int* p_g_raw_data = new int[DATA_NUM];
	for(int j=0;j<DATA_NUM;j++)
		{
			p_g_raw_data[j]=rand()%DATA_NUM; //golbal array	
		}
	start_time = MPI::Wtime();
	qsort(p_g_raw_data,DATA_NUM,sizeof(int),CompareInts);
	end_time = MPI::Wtime();
    cout << "wall clock time (seconds) = "<< scientific << setprecision(4) << end_time-start_time << endl;
	MPI_Finalize();
	}
	return 0;
}