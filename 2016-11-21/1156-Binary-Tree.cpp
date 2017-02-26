#include <iostream>
using namespace std;
template<class T>
class node
{
    public:
        node *getLeft();
        node *getRight();
        void preOrder();
        void setRank(int rank);
        node();
    private:
        node *left;
        node *right;
        int rank;
        int leftNum;
        int rightNum;
        T elem;
};
node::void preOrder()
{
    cout << this->elem;
    
}
node::int getRank()
{
    return this->rank;
}
node::void setRank()
{
    this->rank=rank;
}
node::node()
{
    rank=0;
    elem=0;
    leftNum=0;
    rightNum=0;
    left=nullptr;
    right=nullptr;
}
node::node(int rank,char elem,int left,int right)
{
    if(this->elem)
    {
        if(this->left==rank)
            this->left(
    }
}
int main()
{
    node <char> root;
    int N;
    while(cin >> N)
    {
        while(N--)
        {
            int rank;
            char elem;
            int left;
            int right;
            cin >> rank >> elem >> left >> right;
            root(rank,elem,left,right);
        }
    }
}

