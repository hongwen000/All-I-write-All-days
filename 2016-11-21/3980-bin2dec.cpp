#define BASE1 2 
#define LENGTH 31
#include <cmath> 
#include <iostream> 
using namespace std; 
 
int strlen(const char text[]) 

{ 

    int Length=0; 

    for(;;Length++) 

    { 

        if(text[Length] == 0) 
        { 
            return Length; 
        } 
    } 
} 
int bin2int(char bin) 
{ 
    return bin=='0'?0:1; 
} 
char int2char(int integer) 
{ 
    return (char)(integer+48); 
} 
void reverse(char bin[],int dit) 
{ 
    for(int i=0;i<dit/2;i++) 
    { 
        char temp=bin[i]; 
        bin[i]=bin[dit-i-1]; 
        bin[dit-i-1]=temp; 
    } 
}
void convertBin2Dec(const char bin[], char dec[]) 
{ 
    for(int i=0;i<LENGTH;i++) 
    { 
        dec[i]=0; 
    } 
    long long dec_int=0; 
    int len_bin=strlen(bin); 
    for(int i=0;i<len_bin;i++) 
    { 
        int power=len_bin-i; 
        dec_int+=bin2int(bin[i])*pow(BASE1,power-1); 
    } 
    int dit_int=0; 
    for(;dec_int;dit_int++) 
    { 
        dec[dit_int]=int2char(dec_int%10); 
        dec_int/=10; 
    } 
    reverse(dec,dit_int); 
} 
void convert(const char bin[], char dec[])
{
	long long dec_int=0; 
    int len_bin=strlen(bin); 
	int skip=0;
	for (;skip<len_bin;skip++)
	{
		if(bin[skip]!='0')
			break;
	}
	if(skip==len_bin)
	{
		dec[0]='0';
		dec[1]='\0';
	}
	else 
		convertBin2Dec(bin+skip,dec);
} 


int main() 
{
	int N;
	cin >>N;
    for (int i = 0; i < N; ++ i) { 
        char bin[LENGTH]; 
        cin >> bin; 
        char dec[LENGTH]; 
        convert(bin, dec); 
        cout << dec << endl; 
    } 
} 
