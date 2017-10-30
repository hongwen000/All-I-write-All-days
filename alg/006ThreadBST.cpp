#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;
struct node {
    node() : node(0){}
    node(int x, int y = 0): key(x), lchild(0), rchild(0), parent(0), data(y), l_is_child(true), r_is_child(true){}
    ~node() {
        if(lchild && l_is_child)
            delete lchild;
        if(rchild && r_is_child)
            delete rchild;
    }
    int key;
    node* lchild;
    node* rchild;
    node* parent;
    int data;
    bool l_is_child;
    bool r_is_child;
};

using tree = node;

void insert(tree *T, int k){
    node* x = new node(k);
    if(!T)
        T = new node(k);
    else {
        node * parent = T;
        node * iterator = T;
        while(iterator) {
            parent = iterator;
            if(x->key < iterator->key)
                iterator = iterator->lchild;
            else
                iterator = iterator->rchild;
        }
        x->parent = parent;
        if(parent == nullptr)
            return;
        else if(x->key < parent->key)
            parent->lchild = x;
        else
            parent->rchild = x;
    }
}

node* insertRecur(tree *T, int k) {
    if(!T)
        T = new tree(k);
    else if (k < T->key)
        T->lchild = insertRecur(T->lchild, k);
    else
        T->rchild = insertRecur(T->rchild, k);
    return T;
}

template<typename F>
tree* Tmap(tree* T, F func) {
    if(!T)
        return T;
    else {
        T->lchild = Tmap(T->lchild, func);
        T->key    = func(T->key);
        T->rchild = Tmap(T->rchild, func);
        return T;
    }
}

tree* toTree(const list<int>& lst) {
    if(lst.empty()) return NULL;
    tree * T = new tree(lst.front());
    for(auto i = lst.cbegin(); i != lst.end(); ++i)
        insert(T, *i);
    return T;
}

list<int> toList(tree* T) {
    list<int> ret;
    auto func = [&](int key) {
        ret.push_back(key);
        return key;
    };
    Tmap(T, func);
    return ret;
}

tree* rebuildTree(int *prefix, int* infix, int n) {
    if(n == 0) return NULL;
    node *root = new node(prefix[0]);
    if(n == 1) return root;
    int p = find(infix, infix + n, prefix[0]) - infix;
    root->lchild = rebuildTree(prefix + 1, infix, p);
    root->rchild = rebuildTree(prefix + p + 1, infix + p + 1, n - p - 1);
    return root;
}

int search_recv(tree* T, int data) {
    if(!T)                  return -1;
    if(T->data == data)     return T->key;
    else if(data > T->data) return search_recv(T->rchild, data);
    else                    return search_recv(T->lchild, data);
}

int search(tree* T, int data) {
    while(T && T->data != data) {
        if(T->data > data) T = T->lchild;
        else T = T->rchild;
    }
    return T ? T->key : -1;
}

tree* min(tree* T) {
    while(T->lchild) T = T->lchild;
    return T;
}

tree* max(tree* T) {
    while(T->rchild) T = T->rchild;
    return T;
}

node* succ(node* T) {
    if(T->rchild)   return min(T->rchild);
    else {
        auto p = T->parent;
        while(p && T == p->rchild) {
            T = p;
            p = p->parent;
        }
        return p;
    }
}

node* pred(node* T) {
    if(T->lchild)   return max(T->lchild);
    else {
        auto p = T->parent;
        while(p && T == p->lchild) {
            T = p;
            p = p->parent;
        }
        return p;
    }
}
node* pre = NULL;

void threadizeWorker(tree* T){
    if(T) {
    threadizeWorker(T->lchild);
    if(T->lchild == NULL) {
        T->l_is_child = false;
        T->lchild = pre;
    }
    if(pre && pre->rchild == NULL){
        pre->r_is_child = false;
        pre->rchild = T;
    }
    pre = T;
    threadizeWorker(T->rchild);
    }
}


node* threadPred(node* T) {
    if(T->l_is_child == false)
        return T->lchild;
    else {
        auto p = T->lchild;
        while(p->r_is_child)
            p = p->rchild;
        return p;
    }
}

node* threadSucc(node* T) {
    if(T->r_is_child == false)
        return T->rchild;
    else {
        auto p = T->rchild;
        while(p->l_is_child)
            p = p->lchild;
        return p;
    }
}

int main() {
    int prefix[] = {1, 2, 4, 3, 5, 6};
    int infix[] = {4, 2, 1, 5, 3, 6};
    tree* T = rebuildTree(prefix, infix, 6);
    auto lst = toList(T);
    for(auto i : lst)
        cout  << i << ' ';
    cout << endl;
    threadizeWorker(T);
    auto p = min(T);
    cout << p->key << ' ';
}
