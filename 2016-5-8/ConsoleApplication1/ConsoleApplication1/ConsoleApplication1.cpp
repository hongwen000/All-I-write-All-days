#include "stdafx.h"
//int mpi_input();
//double f(double x);
//double mpi_calc(double local_a, double local_b, double local_n, double h, double(*f)(double x));
//#include <mpi.h>
//#include <iostream>
//int main(int argc, char* argv[])
//{
//	int my_rank, comm_sz, n = 1024, local_n;
//	double a = 0.0, b = 3.0, h, local_a, local_b;
//	double local_ingr, total_ingr;
//	int send_source;
//	MPI_Init(NULL, NULL);
//	MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
//	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
//	h = (b - a)*n;
//	local_n = n / comm_sz;
//	local_a = a + my_rank / comm_sz * (b - a);
//	local_b = local_a + h * local_n;
//	local_ingr = mpi_calc(local_a, local_b,local_n,h,&f);
//	if (my_rank != 0)
//	{
//		MPI_Recv(&local_ingr, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD,MPI_STATUSES_IGNORE);
//	}
//	else
//	{
//		total_ingr = local_ingr;
//		for (send_source = 1; send_source < comm_sz; send_source++)
//		{
//			MPI_Recv(&local_ingr, 1, MPI_DOUBLE, send_source, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
//			total_ingr += local_ingr;
//		}
//	}
//	if (my_rank == 0)
//	{
//		std::cout << total_ingr << std::endl;
//	}
//	MPI_Finalize();
//	return 0;
//}
//
//double f(double x)
//{
//	double y = x;
//	return y;
//}
//
//double mpi_calc(double local_a, double local_b, double local_n, double h, double(*f)(double x))
//{
//	double approx = (f(local_a) + f(local_b)) / 2.0;
//	for (int i = 1; i < local_n; i++)
//	{
//		double x = local_a + i*h;
//		approx += f(x);
//	}
//	approx = approx * h;
//	return approx;
//}
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#define L 3
#define M 2
#define N 3
int A[L][M];
int B[M][N];
int C[L][N];
typedef struct  parameter

{
	int (* a)[M];
	int (* b)[N];
	int (* c)[N];
} _para;
void * calc_one(void* ppara)
{

}
int main()
{
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < M; j++)
		{
			A[i][j] = srand(time(0)) % 20;
			B[j][i] = srand(time(0)) % 20;
		}
	}
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < N; j++)
		{
			C[i][j] = srand(time(0)) % 20;
		}
	}
	_para para;
	para.a = A;
	para.b = B;
	para.c = C;
	_para * ppara;
	ppara = &para;
	pthread_t tid[L][N];
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < N; j++)
		{
			pthread_create(&tid[i][j], NULL,calc_one, (void *)ppara);
		}
	}
}

