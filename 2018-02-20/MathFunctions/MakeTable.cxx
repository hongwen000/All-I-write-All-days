#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int main(int argc, const char *argv[])
{
    double result;
    if (argc < 2)
    {
        return 1;
    }
    std::ofstream fout(argv[1]);
    fout << "double sqrtTable[] = {\n";
    for(int i = 0; i < 10; ++i)
    {
        result = sqrt(i);
        fout << result << ",\n";
    }
    fout << "0};\n";
    fout.close();
    return 0;
}
