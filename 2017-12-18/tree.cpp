#include <stdio.h>

constexpr int N = 1e5;

struct Node{
    Node* lc;
    Node* rc;
    int sum;
    int L, R;
};

Node* build(int a[], int L, int R)
{
    Node* n = new Node;
    n->L = L;
	n->R = R;
    if (L == R) {
        n->sum = a[L];
        n->lc = n->rc = nullptr;
        return n;
    }
    int mid = (L + R) / 2;
    n->lc = build(a, L, mid);
    n->rc = build(a, mid + 1, R);
    n->sum = n->lc->sum + n->rc->sum;
    return n;
}

void change(Node* t, int pos, int v) 
{
    if (t->L == t->R)
    {
        t->sum = v;
        return;
    }
    int mid = (t->L + t->R) / 2;
    if (pos <= mid) //Here must be <= because up there I wrote build(a, mid + 1, R) 
    {
        change(t->lc, pos, v);
    }
    else
    {
        change(t->rc, pos, v);
    }
    t->sum = t->lc->sum + t->rc->sum;
    return;
}

int sum(Node* t, int L, int R)
{
    if (L <= t->L && t->R <= R)
    {
        return t->sum;
    }
    int mid = (t->L + t->R) / 2;
    int ret = 0;
    if (L <= mid) 
    {
        ret += sum(t->lc, L, R);
    }
    if (mid < R)
    {
        ret += sum(t->rc, L, R);
    }
    return ret;
}

int a[N];

