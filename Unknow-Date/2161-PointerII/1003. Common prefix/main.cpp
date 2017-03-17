#include <iostream>
#include <cstring>
using namespace std;
char * prefix(const char * const s1, const char * const s2)
{
int len=0;
if(strlen(s1)>strlen(s2))
{
    len = strlen(s2);
}
else
{
    len = strlen(s1);
}
char * s =new char[len];
for(int i=0;i<len;i++)
{
    if(s1[i]==s2[i])
    {
    s[i]=s1[i];
    }
    else
    {
    break;
    }
}
return s;
}
int main()
{
    char s1[10],s2[20];
    cin >> s1 >>s2;
    cout << prefix(s1,s2) << endl;
    return 0;
}
