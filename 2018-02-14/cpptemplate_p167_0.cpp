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

template <typename T>
void f(T,T);

void (*pf)(char,char) = &f;

class S {
    public:
        template <typename T, int N> operator T[N]& (){
            T[N] arr;
            for (int i = 0; i < v.size() && i < N; i++) {
                arr[i] = v[i];
            }
        };
        template<typename T>
            S(vector<T> && v_):v(v_){}
    private:
        vector<int> v;
};
