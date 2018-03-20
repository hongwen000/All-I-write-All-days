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
#include <gtest/gtest.h>

struct A{};

template<typename T>
struct Puller{};

template<>
struct Puller<A> {
    void print()
    {
        std::cout << "Non const" << std::endl;
    }
};

template<>
struct Puller<const A&> {
    void print()
    {
        std::cout << "Const ref" << std::endl;
    }
};

int main()
{
    Puller<A> pa;
    Puller<const A&> cpaf;
    pa.print();
    cpaf.print();
}
