#include <string>
#include <iostream>
#include <vector>
#include "token.h"
int main()
{
    std::string str;
    while(std::getline(std::cin, str)){
    scan(str);
   // std::vector<TOKEN> v;
   // for(;;) {
   //     TOKEN newToken = getToken();
   //     if(newToken.type == -1)
   //         std::cout << "Error at column " << newToken.lval << std::endl;
   //     if(newToken.type == 0 || newToken.type == -1)
   //         break;
   //     v.push_back(newToken);
   // }
   // for(auto i : v) {
   //     printToken(i);
   // }
    yyparse();
    }
    return 0;
}
