#include <iostream>
using namespace std;
struct BiTree {
    BiTree() : BiTree(0) {};
    BiTree(int n) : key(n), lchid(nullptr), rchid(nullptr) {};
    int key;
    BiTree* lchid;
    BiTree* rchid;
};

void insertBST(BiTree *T, BiTree *S) {
    BiTree* p;
    BiTree* q;
    if(T == nullptr) 
        T = S;
    else {
        p = T;
        while(p) {
            q = p;
            if(S->key < p->key)
                p = p->lchid;
            else
                p = p->rchid;
        }
        if(S->key < q->key)
            q->lchid = S;
        else
            q->rchid = S;
    }
}


