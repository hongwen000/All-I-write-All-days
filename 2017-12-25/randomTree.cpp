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
using namespace std;

struct Node {
    int v;
    Node* p;
};

int main()
{
    int n = 20;
    Node* nodes[n];
    std::vector<int> v;
    for(int i = 0; i < n; ++i) {
        v.push_back(i);
    }
    random_shuffle(v.begin(), v.end());    
    for (int i = 0; i < n; i++) {
        if(v[i] == i)
            swap(v[i])
    }
    
    for (int i = 0; i < n; i++) {
        nodes[i] = new Node{i, (nodes[v[i]])};
    }
        
}
