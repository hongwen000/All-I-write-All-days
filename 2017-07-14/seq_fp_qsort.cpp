#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <iostream>
#include <list>
#include <thread>
#include <mutex>
#include <future>

using namespace std;

template<typename T>
list<T> seq_qsort(list<T> input)
{
    if(input.empty())
        return input;
    list<T> result;
    result.splice(result.begin(), input, input.begin());
    const T& pivot = *result.begin(); 
    auto divid_point = std::partition(input.begin(), input.end(), 
        [&](const T& t){return t < pivot;});
    list<T> lower;
    lower.splice(lower.end(), input, input.begin(), divid_point);
    auto new_lower = seq_qsort(move(lower));
    auto new_higher = seq_qsort(move(input));
    result.splice(result.end(), new_higher);
    result.splice(result.begin(), new_lower);
    return result;
}

template<typename T>
list<T> parr_qsort(list<T> input)
{
    if(input.empty())
        return input;
    list<T> result;
    result.splice(result.begin(), input, input.begin());
    const T& pivot = *result.begin(); 
    auto divid_point = std::partition(input.begin(), input.end(), 
        [&](const T& t){return t < pivot;});
    list<T> lower;
    lower.splice(lower.end(), input, input.begin(), divid_point);
    if(lower.size() >= 1024)
    {
        auto new_lower_fut = async(std::launch::async, &parr_qsort<T>, move(lower));
        auto new_higher = parr_qsort(move(input));
        result.splice(result.end(), new_higher);
        result.splice(result.begin(), new_lower_fut.get());
    }
    else
    {
        auto new_lower = parr_qsort(lower);
        auto new_higher = parr_qsort(input);
        result.splice(result.end(), new_higher);
        result.splice(result.begin(), new_lower);
    }
    return result;
}

int main()
{
    list<int> lst;
    const int N = 10000000;
    for(int i = 0; i < N; ++i)
        lst.push_back(rand() % N);
    auto begin = chrono::steady_clock::now();
    parr_qsort(lst);
    //lst.sort();
    auto end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds> (end - begin).count() << endl;;
}