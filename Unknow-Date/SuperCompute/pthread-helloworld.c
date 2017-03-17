
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#define THREAD_COUNT 8
#define STRING_MAX 32
static char* str[THREAD_COUNT];
void *hello(void *pRank)
{
    int myRank = *(int *)pRank;
    sprintf(str[myRank],"Hello World from thread %d\n",myRank);
    delete[](int *)pRank;
    printf("%s\n",str[myRank]);
    pthread_exit((void *)3);

}
int main()
{
    int * pRank;
    pthread_t threads[THREAD_COUNT];
    for(int iThread=0;iThread < THREAD_COUNT;iThread++)
    {
        str[iThread]=new char[STRING_MAX];
        pRank = new int[1];
        pRank[0]=iThread;
        pthread_create(&threads[iThread],NULL,hello,(void*)pRank);

    }
    for(int iThread=0;iThread < THREAD_COUNT;iThread++)
    {
	//printf("%d\n",threads[iThread]);
	pthread_join(threads[iThread],NULL);
    }
}
