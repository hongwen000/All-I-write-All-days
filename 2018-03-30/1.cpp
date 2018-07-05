#include <iostream>
#include <string>
#include <cerrno>
#include <cstdlib>
 
int main()
{
    const char* p = "     gg10 200000000000000000000000000000 30 -40";
    char *end;
    std::cout << "Parsing '" << p << "':\n";
    long i = std::strtol(p, &end, 10);
        std::cout << "'" << std::string(p, end-p) << "' -> ";
        p = end;
        if (errno == ERANGE){
            std::cout << "range error, got ";
            errno = 0;
        }
        std::cout << i << '\n';
}
