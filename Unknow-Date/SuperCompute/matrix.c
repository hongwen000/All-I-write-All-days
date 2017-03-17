#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>  
#include <sys/timeb.h>

#define L 512
#define M 256
#define N 512
int A[L][M];
int B[M][N];
int C[L][N] = { 0 };
long long getSystemTime() {
    struct timeb t;
    ftime(&t);
    return 1000 * t.time + t.millitm;
}
typedef struct  parameter
{
	int i;
	int j;
} _para;
void * calc_one(void* ppara)
{
	int i =  ((_para *)ppara)->i;
	int j =  ((_para *)ppara)->j;
	for (int k = 0; k < M; k++)
	{
		C[i][j] += A[i][k] * B[k][j];
	}
	//printf("C[%d][%d] is %d\n",i,j,C[i][j]);
	delete (_para *)ppara;
	//printf("%d\n",((_para*)ppara)->i);
	pthread_exit(NULL);
}
int main()
{
    long long start=getSystemTime();

	srand(time(NULL));
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < M; j++)
		{
			A[i][j] = rand() % 5;
			B[j][i] = rand() % 5;
		}
	}
	pthread_t tid[L*N];
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < N; j++)
		{
			_para * ppara = new _para;
			ppara->i = i;
			ppara->j = j;
			pthread_create(&tid[i*L+j], NULL,calc_one, (void *)ppara);
		}
	}
	for (int i=0 ; i< L*N ; i++)
	{
		pthread_join(tid[i],NULL);
	}
    long long end=getSystemTime();
    printf("time: %lld ms\n", end-start);

	return 0;
}
