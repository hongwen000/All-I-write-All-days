// 1156-Binary-Tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
typedef struct input_struct
{
	int rank;
	char elem;
	int left;
	int right;
} input ;
class node
{
public:
	node *getLeft();
	node *getRight();
	void preOrder();
	void setRank(int rank);
	node();
	bool add(int rank, char elem, int left, int right);
	int getRank();
	char getElem();
private:
	node *left;
	node *right;
	int rank;
	int leftNum;
	int rightNum;
	char elem;
};
void node:: preOrder()
{
	cout << this->elem;
	if(this->left!=nullptr)
		this->left->preOrder();
	if (this->right != nullptr)
	this->right->preOrder();
}
int node:: getRank()
{
	return this->rank;
}
void node:: setRank(int Rank)
{
	this->rank = rank;
}
node::node()
{
	rank = 0;
	elem = 0;
	leftNum = 0;
	rightNum = 0;
	left = nullptr;
	right = nullptr;
}


int main()
{
	int N;
	while (cin >> N)
	{
		input inputs[1000];
		bool used[1000];
		for (int i = 0; i < 1000; i++)
			used[i] = false;
		node  root;
		for(int i=0;i<N;i++)
		{
			int rank;
			char elem;
			int left;
			int right;
			cin >> rank >> elem >> left >> right;
			inputs[i].rank = rank;
			inputs[i].elem = elem;
			inputs[i].left = left;
			inputs[i].right = right;
		}
		input root_input;
		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			ans = ans^inputs[i].rank^inputs[i].left^inputs[i].right;
		}
		for (int i = 0; i < N; i++)
		{
			if (inputs[i].rank == ans)
			{
				root_input = inputs[i];
				used[i] = true;
			}
		}
		int rank = root_input.rank;
		char elem = root_input.elem;
		int left = root_input.left;
		int right = root_input.right;
		root.add(rank, elem, left, right);
		bool all_used = true;
		for (int i = 0; i < N; i++)
		{
			all_used = used[i] && all_used;
		}
		while (!all_used){
			for (int i = 0; i < N; i++)
			{
				if (used[i])
					continue;
				else 
				{
					int rank = inputs[i].rank;
					char elem = inputs[i].elem;
					int left = inputs[i].left;
					int right = inputs[i].right;
					bool added= root.add(rank, elem, left, right);
					if(added)
					used[i] = true;
				}
				all_used = true;
				for (int i = 0; i < N; i++)
				{
					all_used = used[i] && all_used;
				}
			}
		} 
		root.preOrder();
		cout << endl;
	}
	return 0;
}

bool node::add(int rank, char elem, int leftNum, int rightNum)
{
	if (this->elem)
	{
		if (this->leftNum == rank)
		{
			this->left = new node();
			return this->left->add(rank, elem, leftNum, rightNum);
		}
		else if (this->rightNum == rank)
		{
			this->right = new node();
			return this->right->add(rank, elem, leftNum, rightNum);
		}
		else
		{
			bool result1 = false;
			bool result2 = false;
			if (this->left != nullptr)
				result1= (this->left)->add(rank, elem, leftNum, rightNum);
			if (this->right != nullptr)
				result2= (this->right)->add(rank, elem, leftNum, rightNum);
			return result1 || result2;
		}
	}
	else
	{
		this->elem = elem;
		this->rank = rank;
		this->leftNum = leftNum;
		this->rightNum = rightNum;
		return true;
	}
	return false;
}
