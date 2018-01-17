#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;
struct node {
    node() : node(0){}
    node(int x, int y = 0): key(x), lch(0), rch(0), parent(0), data(y), left_side_pointer_points_to_left_side_child(true), right_side_pointer_points_to_right_side_child(true){}
    ~node() {
        if(lch && left_side_pointer_points_to_left_side_child)
            delete lch;
        if(rch && right_side_pointer_points_to_right_side_child)
            delete rch;
    }
    int key;
    node* lch;
    node* rch;
    node* parent;
    int data;
    bool left_side_pointer_points_to_left_side_child;
    bool right_side_pointer_points_to_right_side_child;
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
                iterator = iterator->lch;
            else
                iterator = iterator->rch;
        }
        x->parent = parent;
        if(parent == nullptr)
            return;
        else if(x->key < parent->key)
            parent->lch = x;
        else
            parent->rch = x;
    }
}

node* insertRecur(tree *T, int k) {
    if(!T)
        T = new tree(k);
    else if (k < T->key)
        T->lch = insertRecur(T->lch, k);
    else
        T->rch = insertRecur(T->rch, k);
    return T;
}

int search_node(tree* T, int data) {
    while(T && T->data != data) {
        if(T->data > data) T = T->lch;
        else T = T->rch;
    }
    return T ? T->key : -1;
}
void delete_key(tree *T, int k) {
    
}

template<typename F>
tree* Tmap(tree* T, F func) {
    if(!T)
        return T;
    else {
        T->lch = Tmap(T->lch, func);
        T->key    = func(T->key);
        T->rch = Tmap(T->rch, func);
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
    root->lch = rebuildTree(prefix + 1, infix, p);
    root->rch = rebuildTree(prefix + p + 1, infix + p + 1, n - p - 1);
    return root;
}

int search_recv(tree* T, int data) {
    if(!T)                  return -1;
    if(T->data == data)     return T->key;
    else if(data > T->data) return search_recv(T->rch, data);
    else                    return search_recv(T->lch, data);
}

int search(tree* T, int data) {
    while(T && T->data != data) {
        if(T->data > data) T = T->lch;
        else T = T->rch;
    }
    return T ? T->key : -1;
}

tree* min(tree* T) {
    while(T->lch) T = T->lch;
    return T;
}

tree* max(tree* T) {
    while(T->rch) T = T->rch;
    return T;
}

node* succ(node* T) {
    if(T->rch)   return min(T->rch);
    else {
        auto p = T->parent;
        while(p && T == p->rch) {
            T = p;
            p = p->parent;
        }
        return p;
    }
}

node* pred(node* T) {
    if(T->lch)   return max(T->lch);
    else {
        auto p = T->parent;
        while(p && T == p->lch) {
            T = p;
            p = p->parent;
        }
        return p;
    }
}
node* pre = NULL;

void threadizeWorker(tree* T){
    if(T) {
    threadizeWorker(T->lch);
    if(T->lch == NULL) {
        T->left_side_pointer_points_to_left_side_child = false;
        T->lch = pre;
    }
    if(pre && pre->rch == NULL){
        pre->right_side_pointer_points_to_right_side_child = false;
        pre->rch = T;
    }
    pre = T;
    threadizeWorker(T->rch);
    }
}


node* threadPred(node* T) {
    if(T->left_side_pointer_points_to_left_side_child == false)
        return T->lch;
    else {
        auto p = T->lch;
        while(p->right_side_pointer_points_to_right_side_child)
            p = p->rch;
        return p;
    }
}

node* threadSucc(node* T) {
    if(T->right_side_pointer_points_to_right_side_child == false)
        return T->rch;
    else {
        auto p = T->rch;
        while(p->left_side_pointer_points_to_left_side_child)
            p = p->lch;
        return p;
    }
}

void threadTravel(node* T) {
    if(!T) return;
    node* p = T;
    while(p->lch) p = p->lch;
    cout << p->key << ' ';
    while(p->rch) {
        if(p->right_side_pointer_points_to_right_side_child == false) {
            p = p->rch;
            cout << p->key << ' ';
        } else {
            p = p->rch;
            while(p->left_side_pointer_points_to_left_side_child) {
                p = p->lch;
            }
            cout << p->key << ' ';
        }
    }
    cout << endl;
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
    threadTravel(T);
    auto p = min(T);
    cout << p->key << endl;
    auto plast = max(T);
    cout << plast->key << endl;
}
