//管道可用来实现父子进程间的同步
//
//
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
 
static int pfd1[2] ; //父进程在管道1上阻塞等待 来自子进程的消息
static int pfd2[2] ; //子进程在管道2上阻塞等待 来自父进程的消息
 
//初始化同步机制
void
TELL_WAIT(void)
{
    if (pipe(pfd1) < 0 || pipe(pfd2) < 0)
        perror("pipe error!\n") ;
}
 
//通知父进程（即向管道1写入消息，会唤醒在其上等待的父进程）
void
TELL_PARENT(pid_t pid)
{
    if (write(pfd1[1], "c", 1) != 1)
        perror("write error!\n") ;
}
 
//等待父进程(在管道2上读阻塞)
void
WAIT_PARENT(int pid)
{
    char c ;
    if (read(pfd2[0], &c, 1) != 1)
        perror("read error\n") ;
 
    //检查是否是来自父进程的数据（防止伪造）
    if (c != 'p')
        perror("WAIT_PARENT:incorrectdata\n") ;
}
 
//通知子进程（即向管道2写入消息，会唤醒在其上等待的子进程）
void
TELL_CHILD(pid_t pid)
{
    if (write(pfd2[1], "p", 1) != 1)
        perror("write error!\n") ;
}
 
//等待子进程(在管道1上读阻塞)
void
WAIT_CHILD(int pid)
{
    char c ;
    if (read(pfd1[0], &c, 1) != 1)
        perror("read error\n") ;
 
    //检查是否是来自子进程的数据（防止伪造）
    if (c != 'c')
        perror("WAIT_PARENT:incorrectdata\n") ;
}
 
//------------------测试程序--------------------
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
 
int
main(void)
{
    int i = 0 ;
    int cnt = 0 ;
    pid_t pid ;
 
    //为同步机制初始化
    TELL_WAIT() ;
 
    if ((pid = fork()) < 0)
        perror("fork error") ;
    else if (pid > 0) //父进程
    {
        for (i = 0; i < 3; ++i)
        {
            printf("From parent :%d\n", i) ;
        }
        TELL_CHILD(pid) ;
        WAIT_CHILD(pid) ;
        for (; i < 6; ++i)
        {
            printf("From parent :%d\n", i) ;
        }
        TELL_CHILD(pid) ;
        return 0 ;
    }
    else //子进程
    {
        WAIT_PARENT(getppid()) ;
        for (i = 0; i < 3; ++i)
        {
            printf("From child : %d\n",i) ;
        }
        TELL_PARENT(getppid()) ;
        WAIT_PARENT(getppid()) ;
        for (; i < 6; ++i)
        {
            printf("From child :%d\n", i) ;
        }
        return 0 ;
    }
}
//只要有：阻塞-等待的机制 都可以考虑实现进程间同步。（信号、管道等）
