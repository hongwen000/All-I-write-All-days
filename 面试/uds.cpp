#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <string.h>
void killHandler(int num)
{
    printf("You want kill me ? :) %d\n", num);
}
int main()
{
    signal(SIGINT, killHandler);
    while(true);
}