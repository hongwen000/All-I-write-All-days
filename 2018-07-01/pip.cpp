#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <string.h>
int main() {
  int x, fd[2];
  char buf[30], s[30];
  pipe(fd);
  if(fd[0] < 0 || fd[1] < 0)
  {
    printf("open pipe error\n");
  }
  else
  {
      printf("Open file %d, %d\n", fd[0], fd[1]);
  }
  x = fork();
  if (x == 0) {
    sprintf(buf, "abcd");
    close(fd[0]);
    write(fd[1], buf, strlen(buf) + 1);
    printf("%d process exit\n", x);
    exit(0);
  } 
  else {
    wait(0);
    printf("%d reads\n", x);
    close(fd[1]);
    read(fd[0], s, 30);
    printf("%s", s);
  }
}
