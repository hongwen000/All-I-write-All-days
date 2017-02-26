#include <iostream>
using namespace std;
int sum(int n,char base)
{
    int sum=0;
    while (n != 0)
    {
    switch (base)
    {
    case 'a':{
        sum+= n%10;
        n /= 10;
        break;}
        
    case 'b':{
        sum+= n%12;
        n /= 12;
        break;}
        
    case 'c':{
        sum+= n%16;
        n /= 16;
        break;}
     }   
          
    }
    return sum;
}
int main()
{
for (int i = 2992; i <= 9999; i++)
{

        if (sum(i,'a') == sum(i,'b') && sum(i,'a') == sum(i,'c') && sum(i,'b') == sum(i,'c'))
            cout << i <<endl;

}
    return 0;
} 