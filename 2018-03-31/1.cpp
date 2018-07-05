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

class sh{
private:
    static constexpr int buf_size = 512;
    static constexpr int SUCCESS = 0;
    char buf[buf_size];
    struct prog_entry {
        char name[32];
        int lba;
    };
    prog_entry progs[16];
    int prog_cnt = 0;
    size_t pos = 0;
    int exec()
    {
        return SUCCESS;
    }
    void read_prog_record()
    {
        char record_buf[] = "5\npopup-1\5";
        int cnt;
        sscanf(record_buf, "%d", &cnt);
        std::cout << cnt << std::endl;
    }
public:
    sh(){
        memset(buf, 0, buf_size);
        read_prog_record();
    }
    void run () {
        while(true)
        {
            char in = getchar();
            if (in == 13)
            {
                exec();
                memset(buf, 0, buf_size);
                pos = 0;
                continue;
            }
            putchar(in);
            buf[pos++] = in;
        }
    }
};
int main()
{
    char record_buf[] = "5\npopup-1\n5";
    char buf1[32];
    char buf2[32];
    char buf3[32];
    sscanf(record_buf, "%s%s%s", buf1, buf2, buf3);
    std::cout << buf1 << std::endl;
    std::cout << buf2 << std::endl;
    std::cout << buf3 << std::endl;
    //sh sh1;
}
