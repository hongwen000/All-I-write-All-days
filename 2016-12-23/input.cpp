#include <stdio.h>
int main()
{
    int number = 100;
    int array[number];
    int i = 0;
    while(i != number && scanf("%d", &array[i])!=EOF){i++;}
} 
