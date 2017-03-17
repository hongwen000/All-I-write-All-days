#include <iostream>
#include <cstring>
using namespace std;
char * sortString(const char * const s)
{
    int len=strlen(s);
    char * str = new char[len];
    strcpy(str,s);
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (str[i] > str[j])
            {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
return str;
}
void sortString(const char * const s, char * s1)
{
strcpy(s1,sortString(s));
}

int main()
{
    cout << sortString( "Hello world!") << endl;
    return 0;
}
