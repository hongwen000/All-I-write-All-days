#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int num_of_space = n - 1;                       //每行行首的空格数，第一行为n-1个
    for(int i = 0; i < n; ++i)                      //逐行输出
    {
        for(int j = i; j < num_of_space; ++j)       //输出空格
        {
            printf(" ");
        }
        for(int k = 0; k < n; ++k) 
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
