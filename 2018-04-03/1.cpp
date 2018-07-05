#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <utility>
#include <vector>
#include <type_traits>
using namespace std;
    struct cmd{
        int start;
        int cnt = 0;
    };
    cmd cmds[128];
char *inputs[128];
    int split_input(char* buf)
    {
        int i = 0;
        char * p = buf;
        while(*p && isspace(*p)){
            ++p;
        };
        bool con = false;
        while (*p)
        {
            if(isspace(*p))
            {
                *p = '\0';
                if(con)
                {
                con = false;
                ++i;
                }
            }
            else
            {
                if(!con)
                {
                    inputs[i] = p;
                    con = true;
                }
            }
            ++p;
        }
        if(con) ++i;
        return i;
    }
    int split_batch(char** inputs, int input_cnt)
    {
        int i = 0;
        int p = 0;
        while(strcmp(inputs[p], ";") == 0){
            ++p;
        };
        bool con = false;
        while (p < input_cnt)
        {
            if(strcmp(inputs[p], ";") == 0)
            {

                if(con)
                {
                    con = false;
                    ++i;
                }
            }
            else
            {
                if(!con)
                {
                    cmds[i].start = p;
                    cmds[i].cnt++;
                    con = true;
                }
                else {
                    cmds[i].cnt++;
                }
            }
            ++p;
        }
        if(con) ++i;
        return i;
    }
int main()
{
    char buf[512];
    string s;
    getline(cin, s);
    memcpy(buf, s.c_str(), s.length() + 1);
    auto i = split_input(buf);
    auto j = split_batch(inputs, i);
    for(auto ii = 0; ii < j; ++ii)
    {
        std::cout << cmds[ii].start << std::endl;
        std::cout << cmds[ii].cnt << std::endl;
    } 
}
