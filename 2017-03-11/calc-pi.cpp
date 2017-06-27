#include <cstdio>
#include <iostream>
#include <functional>
using namespace std;
using pi_type = long double;
pi_type sum(function<pi_type(pi_type)> term, pi_type a, function<pi_type(pi_type)> next, pi_type b) 
{
    function<pi_type(pi_type, pi_type)> iter = [&](pi_type j, pi_type ans) -> pi_type
    {
        if (j > b)
            return ans;
        else
            return iter(next(j), (term(j) + ans));
    };
    return iter(a, 0.0);
}
int main()
{
    auto pi_sum = bind(sum                          \
                , [](pi_type i) -> pi_type          \
                { return 1.0 / ( i * ( i + 2.0)); } \
                , placeholders::_1                  \
                , [](pi_type i) -> pi_type          \
                { return i + 4.0; }                 \
                , placeholders::_2);
    pi_type iter_times;
    cin >> iter_times;
    cout << 8.0 * pi_sum(1, iter_times) << endl;
    return 0;
}
//sdfahoi