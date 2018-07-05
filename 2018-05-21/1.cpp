#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <algorithm>
#include <iostream>

char str[80] = "129djwqhdsajd128dw9i39ie93i8494urjoiew98kdkd";
int LetterNr = 0;
void CountLetter()
{
    std::for_each(std::cbegin(str), std::cend(str), [](const char c){isalpha(c) ? LetterNr++ : 0;});
    std::cout << "In children " << LetterNr << std::endl;
}
int main() {
  int pid;
  char ch;
  pid = fork();
  if (pid == -1)
    printf("error in fork !");
  if (pid) {
    ch = wait(nullptr);
    CountLetter();
    printf("LetterNr = %d\n", LetterNr);
  }
  else {
    CountLetter();
    printf("LetterNr = %d\n", LetterNr);
    exit(0);
  }
}

