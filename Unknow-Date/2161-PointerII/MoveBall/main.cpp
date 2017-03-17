#include <iostream>

using namespace std;
class Balls
{
public:
Balls(int a);
void move1(int i,int j);
void move2(int i,int j);
void show();
private:
int getpostion(int a);
int len;
int * BallLine;
};
Balls::Balls(int a)
{
    len=a;
    BallLine = new int [len];
    for(int i=0;i<len;i++)
    {
        (BallLine)[i]=i+1;
    }
}
void Balls::move1(int i,int j)
{
    i=getpostion(i);
    j=getpostion(j);
    int tmp=(BallLine)[i-1];
    for(int n=0;n<len;n++)
    {
        if(n>i-1 && n <j-1)
        {
            (BallLine)[n-1]=(BallLine)[n];
        }
    }
    (BallLine)[j-2]=tmp;
}
void Balls::move2(int i,int j)
{
    i=getpostion(i);
    j=getpostion(j);
    int tmp=(BallLine)[i-1];
    for(int n=0;n<len;n++)
    {
        if(n>i-1 && n <j)
        {
            (BallLine)[n-1]=(BallLine)[n];
        }
    }
    (BallLine)[j-1]=tmp;
}
int Balls::getpostion(int a)
{
for(int i=0;i<len;i++)
{
if(BallLine[i]==a)
{
return i+1;
}
}
}

void Balls::show()
{
    for(int n=0;n<len;n++)
    {
        cout << (BallLine)[n] <<' ';
    }
    cout <<endl;
}
int main()
{
    int numt=0;
    cin >> numt;
    while(numt)
    {
        int numb=0,numi=0;
        cin >>numb >> numi;
        Balls b(numb);
        while(numi)
        {
            int i1,i2,i3;
            cin >> i1>>i2>>i3;
            if(i1==1)
                b.move1(i2,i3);
            else
                b.move2(i2,i3);
            numi--;
        }
        b.show();
        numt--;
    }
    return 0;
}
