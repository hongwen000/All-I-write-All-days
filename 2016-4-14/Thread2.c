#include <stdio.h>
#include <pthread.h>
int count=0;
void *threadPlus(void *row)
{
	
	while(1)
	{
	count++;
	printf("%d\n",count);
	}
	return NULL;
}
void *threadSub(void *row)
{
	
	while(1)
	{
	count--;
	printf("%d\n",count);
	}
	return NULL;
}
int main()
{
	int i=1;
	pthread_t tid1;
	pthread_t tid2;
	pthread_create(&tid1,NULL,threadPlus,(void*)&i);
	pthread_create(&tid2,NULL,threadSub,(void*)&i);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return 0;
}
