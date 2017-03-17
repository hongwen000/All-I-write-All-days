#include <stdio.h>  
#include <sys/types.h>  
#include <unistd.h>  
int main(void)
{
	int i, a = 0;
	pid_t pid;
	pid = fork();
	if (pid != 0)a = 100;
	if (pid == 0)
		printf("%d\n", a);
	else
		printf("%d\n", a);
	return 0;
}
