#include <iostream>
#include <string>
inline
int myplus(int a, int b)
{
    return a + b;
}
inline
double myplus(double d, double c)
{
    return d + c;
}
inline
std::string myplus(std::string str1, std::string str2)
{
    return str1 + str2;
}
int main() {
    int n;
      int a,b;
      double c,d;
      std::string str1,str2;
      std::cin>>n;
      while(n--)
      {
          std::cin>>a >> b ;
          std::cin>>c >> d;
          std::cin >> str1 >>str2;
          std::cout <<myplus(a, b) << std::endl;
          std::cout <<myplus(d, c) << std::endl;
          std::cout <<myplus(str1, str2) << std::endl;
      } 
      return 0;
}


