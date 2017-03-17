void mpi_input(int my_rank, int comm_sz, double* a, double* b, int* n);
double f(double x);
double mpi_calc(double local_a, double local_b, double local_n, double h, double(*f)(double x));
#include <mpi.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
	int my_rank, comm_sz, n = 1024, local_n;
	double a = 0.0, b = 3.0, h, local_a, local_b;
	double local_ingr, total_ingr;
	int send_source;
	double start_Time,finish_Time;
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	mpi_input(my_rank,comm_sz,&a,&b,&n);
	start_Time = MPI_Wtime();
	h = (b - a)/n;
	local_n = n / comm_sz;
	local_a = a + my_rank*local_n*h;
	local_b = local_a + h * local_n;
	local_ingr = mpi_calc(local_a, local_b,local_n,h,&f);
/*
	if (my_rank != 0)
	{
		MPI_Send(&local_ingr, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
	}
	else
	{
		total_ingr = local_ingr;
		for (send_source = 1; send_source < comm_sz; send_source++)
		{
			MPI_Recv(&local_ingr, 1, MPI_DOUBLE, send_source, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
			total_ingr += local_ingr;
		}
	}
*/
        MPI_Reduce(&local_ingr,&total_ingr,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
	finish_Time = MPI_Wtime();
	if (my_rank == 0)
	{
		printf("%f\n",total_ingr);
		printf("Elapsed time = %e seconds \n", finish_Time -start_Time);
	}
	MPI_Finalize();
	return 0;
}

double f(double x)
{
	double y = x;
	return y;
}

double mpi_calc(double local_a, double local_b, double local_n, double h, double(*f)(double x))
{
	double approx = (f(local_a) + f(local_b)) / 2.0;
	for (int i = 1; i < local_n; i++)
	{
		double x = local_a + i*h;
		approx += f(x);
	}
	approx = approx * h;
	return approx;
}
void mpi_input(int my_rank, int comm_sz, double* a, double* b, int* n)
{
	int destination =1 ;
	if(my_rank == 0)
	{
		printf("Please input a , b , n \n");
		scanf("%le,%le,%d",a,b,n);
		printf("%le,%le,%d\n",*a,*b,*n);
		for(destination = 1; destination < comm_sz ; destination ++)
		{
			MPI_Send(a,1,MPI_DOUBLE,destination,0,MPI_COMM_WORLD);
			MPI_Send(b,1,MPI_DOUBLE,destination,0,MPI_COMM_WORLD);
			MPI_Send(n,1,MPI_INT,destination,0,MPI_COMM_WORLD);
		}
	}
	else
	{
		MPI_Recv(a,1,MPI_DOUBLE,0,0,MPI_COMM_WORLD,MPI_STATUSES_IGNORE);
		MPI_Recv(b,1,MPI_DOUBLE,0,0,MPI_COMM_WORLD,MPI_STATUSES_IGNORE);
		MPI_Recv(n,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUSES_IGNORE);
	}
}
