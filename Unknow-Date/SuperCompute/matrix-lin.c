#include<iostream>
#include<iomanip>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>  
#include <sys/timeb.h>
#include <stdio.h>

using namespace std;
#define L 512
#define M 256
#define N 512
long long getSystemTime() {
    struct timeb t;
    ftime(&t);
    return 1000 * t.time + t.millitm;
}
int main()
{
long long start=getSystemTime();
int i,j,k;
int A[L][M], B[M][N] ;
int result[L][N] = {0};
srand(time(NULL));
for (int i = 0; i < L; i++)
{
	for (int j = 0; j < M; j++)
	{
		A[i][j] = rand() % 5;
		B[j][i] = rand() % 5;
	}
}

for (i = 0; i < L; i++)
	for (k = 0; k < M; k++)
		for (j = 0; j < N; j++)
		{
			result[i][j] += A[i][k] * B[k][j];
		}

for (i = 0; i < N; i++)
{
	cout << endl;
	for (j = 0; j < N; j++)
		cout << setw(6) << result[i][j];
}
    long long end=getSystemTime();
    printf("time: %lld ms\n", end-start);
return 0;
}
