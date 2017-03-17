#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int parseBinary(const char * const binaryString)
{
int len=strlen(binaryString);
int answer=0;
for(int i=0;i<len;i++)
{
int power= len-i-1;
answer+=pow((2*(((int)binaryString[i])-48)),power);
}
return answer;
}

int main()
{
    cout << parseBinary("10001") << endl;
    return 0;
}
