// Analyzing scores.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
typedef struct Node
{
	int Grade;
	struct Node * Next;
}Node;
void Echo_Answer(Node * L);
Node * New_Node();
void Destruct_Node(Node * L);
int Deal_Case(Node * Head_Node, Node * const Head_Node_Addr, int & Number_Case);
void Echo_Answer(Node * L)
{
	Node * HeadNode = L;
	int Sum_Grade(0);
	int Sum_Count(0);
	while (HeadNode->Next != NULL)
	{
		Sum_Grade += HeadNode->Grade;
		HeadNode = HeadNode->Next;
		Sum_Count++;
	}
	if (Sum_Grade == 0)
	{
		HeadNode = L;
		while (HeadNode->Next != NULL)
		{
			cout << HeadNode->Grade << ' ';
			HeadNode = HeadNode->Next;
		}
		cout << endl;
		exit(255);
	}
	int Average = Sum_Grade / Sum_Count;
	HeadNode = L;
	while (HeadNode->Next != NULL)
	{
		if (HeadNode->Grade == Average)
		{
			cout << HeadNode->Grade << ' ';
		}
		HeadNode = HeadNode->Next;
	}
	cout << endl;
}
Node * New_Node()
{
	Node * Ptr_Node = new Node;
	Ptr_Node->Grade = 0;
	Ptr_Node->Next = NULL;
	return Ptr_Node;
}
void Destruct_Node(Node * L)
{
	Node * HeadNode = L;
	Node * HeadNode_Next = HeadNode->Next;
	while (HeadNode_Next != NULL)
	{
		delete HeadNode;
		HeadNode = HeadNode_Next;
		HeadNode_Next = HeadNode_Next->Next;
	}
}
int Deal_Case(Node * Head_Node, Node * const Head_Node_Addr, int & Number_Case)
{
	int Number_Input;
	while (cin >> Number_Input)
	{
		if (Number_Input < 0)
		{
			Echo_Answer(Head_Node_Addr);
			Number_Case--;
			return 0;
		}
		Head_Node->Next = New_Node();
		Head_Node->Grade = Number_Input;
		Head_Node = Head_Node->Next;
	}
}
int main()
{
	int Number_Case;
	cin >> Number_Case;
	while (Number_Case > 0)
	{
		Node * Head_Node = New_Node();
		Node * const Head_Node_Addr = Head_Node;
		Deal_Case(Head_Node, Head_Node_Addr, Number_Case);
		Destruct_Node(Head_Node_Addr);
	}
	return 0;
}

