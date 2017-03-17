#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
int A[8][8];
int X[8],Y[8];
void *threadX(void *row)
{
	int i =*(int *) row;
	Y[i]=0;
	for(int k=0;k<8;k++)
	{
		Y[i]+=A[i][k]*X[k];
	}
	free(row);
	return NULL;
}
int main()
{
	//input A X
	for(int i=0;i<8;i++)
	{
		X[i]=3;
		for(int j=0;j<8;j++)
		{
			A[i][j]=2;
		}
	}
	pthread_t tid[8];
	for(int j=0;j<8;j++)
	{
		void * n =  malloc(sizeof (int));
		pthread_create(&tid[j],NULL,threadX,n);
	}
	for(int i=0;i<8;i++)
	{
		pthread_join(tid[i],NULL);
	}
	for(int i=0;i<8;i++)
	{
		printf("%d\n",Y[i]);
	}
	return 0;
}
