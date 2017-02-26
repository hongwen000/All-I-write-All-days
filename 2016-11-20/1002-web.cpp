#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int prime[10001];
int number[1001];
int n, m, d;

bool isPrime(int num)
{
    if(num == 1) return false;
       for(int i = 2; i < num; i++)
    {
      if(num % i == 0) return false;       
    } 
    return true;
}

void setPrime()
{
    for(int i = 2; i < 10001; i++)
       if(isPrime(i))
             prime[i] = 1;    
}



bool isValid(int row, int num)
{
    for(int i = 1; i < row; i++)
    {
        if(number[i] == num) 
           return false;
    }
    int sum = num;
    for(int i = row -  1; i >= 1 && i >= row - d + 1; i--)
    {
        sum += number[i];
        if(prime[sum]) return false;
    }
    return true;
}


bool dfs(int row)
{
    if(row == m - n + 2)
    {
        for(int i = 1; i <= m - n + 1; i++)
        {
            cout << number[i] << ((i == m - n + 1)? "": ",");
        }
        cout<<endl;
        return true;
    }
    
    for(int num = n; num <= m; num++)
    {
        number[row] = num;
        if(isValid(row, num) && dfs(row+1))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    setPrime();
    cin>>n>>m>>d;
    while(n || m || d)
    {
        if(!dfs(1))
        cout<< "No anti-prime sequence exists."<<endl;
        cin >> n >> m >> d;
    }
    return 0;
}