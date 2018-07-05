#include "cpr/include/cpr/cpr.h"
int main(int argc, const char *argv[])
{
    if(argc < 2) return 0;
    auto r = cpr::Get(cpr::Url{argv[1]});
    r.status_code;
    r.header["content-type"];
    r.text;
    return 0;
}
