#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char* hello(char* what)
{
    char* ret = (char*)malloc(strlen(what) + 7);
    strcpy(ret, "hello ");
    for(int i = 0; i < strlen(what) + 1; ++i)
    {
        ret[6 + i] = what[i];
    }
    printf("%s", ret);
    return "hello world";
}
int main()
{
    hello("world");
}