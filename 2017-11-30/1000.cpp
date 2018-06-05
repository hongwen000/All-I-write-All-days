#include <iostream>
using namespace std;
struct node{
    node(int _v) : v(_v), lch(NULL), rch(NULL) {}
    int v;
    node* lch;
    node* rch;
};
node* insert(node* T, int n) {
    if(T == NULL) return new node(n);
    else if(n < T->v) T->lch = insert(T->lch, n);
    else T->rch = insert(T->rch, n);
    return T;
}
void pre(node* T) {
    cout << T->v << ' ';
    if(T->lch)    pre(T->lch);
    if(T->rch)    pre(T->rch);
}
void mid(node* T) {
    if(T->lch)     mid(T->lch);
    cout << T->v << ' ';
    if(T->rch)     mid(T->rch);
}
int main() {
    int N;
    while(cin >> N, N != 0)
    {
        int t;
        node* T = NULL;
        for(int i = 0; i < N; ++i) {
            cin >> t;
            T = insert(T, t);
        }
        mid(T);
        cout << endl;
        pre(T);
        cout << endl;
    }
}
