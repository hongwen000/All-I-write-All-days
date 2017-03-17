#include <stdio.h>  
#include <sys/types.h>  
#include <unistd.h>  
int main(void)  
{  
   int i, a=0;  
   pid_t pid;
   pid=fork();   //这个语句执行完毕后，系统内就有一个新进程了；
   if(pid!=0)a=1;
   if(pid==0)
         printf("%d\n",a);
   else 
         printf("%d\n",a);
   return 0;  
} 
