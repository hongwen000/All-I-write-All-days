#include<stdio.h>
#include<string.h>
/*
void change_const(const char *s){
((char*)s)[0]='B';
}
*/
int main(){
//char s[]="Hello";
char *sp="Hello";
*sp='j';
//change_const(s);
printf("%s",sp);
return 0;
}  