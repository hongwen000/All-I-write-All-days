#include <iostream>
using namespace std;
void hanoi(const char from[], const char to[], const char relay[],int num)
{
    if(num==1)
    {
       cout << "Move "<<num<<" From "<< from <<" To "<<to<<endl;
       return ;
    }
    hanoi(from,relay,to,num-1);
    cout <<"Move "<<num<<" From "<<from<<" To "<<to<<endl;
    hanoi(relay,to,from,num-1);
}
int main()
{
    hanoi("T1","T2","T3",3);
}
