#include <iostream>

using namespace std;
int times;
int hanoi(int n)
{
if(n>1)
{
return 1+hanoi(n-1)+hanoi(n-1);
}
else
return 1;
}

int main()
{

    cout << hanoi(3) << endl;
    return 0;
}
