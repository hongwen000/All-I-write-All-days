 #include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <iterator>
#include <stack>
#include <deque>
#include <climits>
using namespace std;
typedef int T;
struct BinaryNode{
  T data;
  BinaryNode *left, *right;
  BinaryNode(T d, BinaryNode *l=NULL, BinaryNode* r=NULL):data(d), left(l), right(r) {};
};

int findMin(const BinaryNode* root) {
    set<const BinaryNode*> visited;
    deque<const BinaryNode*> S;
    S.push_back(root);
    visited.insert(root);
    int min = INT_MAX;
    while(!S.empty()){
        const BinaryNode* p = S.front();
        min = min < p->data ? min : p->data;
        S.pop_front();
        if(p->left && !visited.count(p->left)){
            S.push_back(p->left);
            visited.insert(p->left);
        }
        if(p->right && !visited.count(p->right)) {
            S.push_back(p->right);
            visited.insert(p->right);
        }
    }
    return min;
}

//以下是输出用的函数，提交时一定删除！！！！！
//！！！！！！！！！！！！！！！！

int main() {
    BinaryNode* T = new BinaryNode(5);
    T->left = new BinaryNode(3);
    T->right = new BinaryNode(-1, new BinaryNode(9), new BinaryNode(-4));
    cout << findMin(T) << endl;
}
