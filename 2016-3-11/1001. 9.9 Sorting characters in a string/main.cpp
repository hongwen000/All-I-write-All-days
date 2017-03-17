#include <iostream>
#include <string>
using namespace std;
string sort(string &s);
string sort(string &s)
{
    bool flag=true;
    for(int i=0;i<s.length() && flag;i++)
    {
        flag=false;
        for(int j=s.length()-1 ;j>i ;j--)
        {
            if(s.at(j)<s.at(j-1))
            {
            char temp=s[j];
            s[j]=s[j-1];
            s[j-1]=temp;
            flag=true;
            }
        }
    }
return s;
}
int main()
{
    string Test_String;
    cin >>Test_String;
    cout << sort(Test_String) << endl;
    return 0;
}
