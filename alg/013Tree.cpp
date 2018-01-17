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
#include <gtest/gtest.h>
struct Node {
    Node(char _v) : v(_v){}
    char v = '\0';
    Node* lch = nullptr;
    Node* rch = nullptr;
};

void levelTravel(Node* T)
{
    if(!T) return;
    queue<Node*> q;
    q.push(T);
    while(!q.empty())
    {
        Node* n = q.front();
        q.pop();
        std::cout << n->v << ' '; 
        if(n->lch) q.push(n->lch);
        if(n->rch) q.push(n->rch);
    }
    cout << endl;
}

int depth(Node* T)
{
    if(!T) return 0;
    int dlch = depth(T->lch);
    int drch = depth(T->rch);
    return max(dlch, drch) + 1;
}

static Node* T = new Node('-');

TEST(test, levelTravel)
{
    levelTravel(T);

}

TEST(test, depth)
{
    EXPECT_TRUE(depth(T) == 5);
}

int main(int argc, char *argv[])
{
    T->lch = new Node('+');
    T->rch = new Node('/');
    T->rch->lch = new Node('e');
    T->rch->rch = new Node('f');
    T->lch->rch = new Node('*');
    T->lch->lch = new Node('a');
    T->lch->rch->rch = new Node('-');
    T->lch->rch->lch = new Node('b');
    T->lch->rch->rch->lch = new Node('e');
    T->lch->rch->rch->rch = new Node('d');
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
