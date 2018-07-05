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
int main(int argc, const char *argv[])
{
    char buf [] = "abcdefg";

    auto MAX_BUF = sizeof(buf);
    auto pos = 2;
    memmove(buf+pos, buf+pos + 1, MAX_BUF - pos);
    cout << buf << endl;
    return 0;
}
