// 1003. Cycling the words.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
template <typename Type> class CircularList;
template <typename Type> class ListNode
{
public:
	Type m_data;
	ListNode *m_pnext;

	friend class CircularList<Type>;//因为构造newhead的时候需要调用ListNode的私有构造函数
	ListNode() :m_pnext(NULL) {};
	ListNode(const Type item, ListNode<Type> *next = NULL) :m_data(item), m_pnext(next) {};
	~ListNode() { m_pnext = NULL; }

	Type Getdata()//留一个接口，使用户能够访问ListNode的数据
	{
		return m_data;
	}
};
template<typename Type> class CircularList {
public:
	CircularList() :head(new ListNode<Type>()) {
		head->m_pnext = head;
	}
	~CircularList() {
		MakeEmpty();
		delete head;
	}
public:
	void MakeEmpty();	//clear the list
	int Length();		//get the length
						//ListNode<Type> *Find(Type value,int n);	//find the nth data which is equal to value
	ListNode<Type> *Find(int n);			//find the nth data
	bool Insert(Type item, int n = 0);			//insert the data into the nth data of the list
	Type Remove(int n = 0);					//delete the nth data
	bool RemoveAll(Type item);				//delete all the datas which are equal to value
	Type Get(int n);	//get the nth data
	void Print();		//print the list
	ListNode<Type> *head;

};

template <typename Type> void CircularList<Type>::MakeEmpty()
{
	ListNode<Type>* pdel = head;
	while (head->m_pnext != head)
	{
		pdel = head->m_pnext;
		head->m_pnext = pdel->m_pnext;
		delete pdel;
	}
}

template <typename Type> int CircularList<Type>::Length()
{
	ListNode<Type> *pmove = head;
	int count(0);
	while (pmove->m_pnext != head)
	{
		pmove = pmove->m_pnext;
		++count;
	}
	//cout<<count<<endl;
	return count;
}

template <typename Type> ListNode<Type>* CircularList<Type>::Find(int n)
{
	if (n<0 || n>CircularList<Type>::Length())
	{
		cout << "the n is out of boundary!" << endl;
		exit(-1);
	}
	ListNode<Type>* pmove = head->m_pnext;
	for (int i = 0; i<n; i++)
		pmove = pmove->m_pnext;
	cout << "Found!" << endl;
	return pmove;
}

template <typename Type> bool CircularList<Type>::Insert(Type item, int n)
{
	if (n<0 || n>CircularList<Type>::Length())
	{
		cout << "the n is out of boundary!" << endl;
		return false;
	}
	ListNode<Type>* pmove = head;
	for (int i = 0; i<n; i++)
		pmove = pmove->m_pnext;

	ListNode<Type>* newnode = new ListNode<Type>(item);
	if (newnode == NULL)
	{
		cout << "Application error!" << endl;
		return false;
	}
	newnode->m_pnext = pmove->m_pnext;
	pmove->m_pnext = newnode;
	return true;
}

template <typename Type> Type CircularList<Type>::Remove(int n)
{
	if (n<0 || n>CircularList<Type>::Length())
	{
		cout << "the n is out of boundary!" << endl;
		return false;
	}
	ListNode<Type>* pmove = head;
	for (int i = 0; i<n; i++)
	{
		pmove = pmove->m_pnext;
	}
	ListNode<Type>* pdel = pmove->m_pnext;
	Type temp = pdel->m_data;
	pmove->m_pnext = pdel->m_pnext;
	delete pdel;
	return temp;
}

template <typename Type> bool CircularList<Type>::RemoveAll(Type item)
{
	ListNode<Type>* pmove = head;
	ListNode<Type>* pdel = head->m_pnext;
	while (pdel != head)
	{
		if (pdel->m_data == item)
		{
			pmove->m_pnext = pdel->m_pnext;
			cout << "Found and Deleted!" << endl;
			delete pdel;
			pdel = pmove->m_pnext;//主要要重新给pdel赋值，因为前面delete了
			continue;
		}
		pmove = pmove->m_pnext;
		pdel = pdel->m_pnext;
	}
	return true;
}

template <typename Type> Type CircularList<Type>::Get(int n)
{
	if (n<0 || n>CircularList<Type>::Length())
	{
		cout << "the n is out of boundary!" << endl;
		return false;
	}
	ListNode<Type>* pmove = head->m_pnext;
	for (int i = 0; i<n; i++)
		pmove = pmove->m_pnext;

	return pmove->m_data;
}

template <typename Type> void CircularList<Type>::Print()
{
	cout << "head";
	ListNode<Type>* pmove = head->m_pnext;
	while (pmove != head)
	{
		cout << "--->" << pmove->m_data;
		pmove = pmove->m_pnext;
	}
	cout << "--->head" << endl;
}
int break_sentence(string sentence, CircularList <string> & list);
int main()
{
	CircularList <string> list;
	int number_of_words;
	string sentence;
	getline(cin, sentence);
	number_of_words=break_sentence(sentence, list);
	for (ListNode <string> * head_iter = (list.head)->m_pnext; head_iter != list.head; head_iter = head_iter->m_pnext)
	{
		int print_count = 0;
		ListNode <string> * print_iter = head_iter;
		for (; print_count < number_of_words; print_iter=print_iter->m_pnext)
		{
			if (print_iter != list.head)
			{
				cout << print_iter->Getdata() << ' ';
				print_count++;
			}
		}
		cout << endl;
	}
    return 0;
}

int break_sentence(string sentence, CircularList <string> & list)
{
	int position_of_blank;
	int number_of_words=0;
	position_of_blank = sentence.find(' ');
		while (position_of_blank != -1)
		{
			list.Insert(sentence.substr(0, position_of_blank), number_of_words);
			sentence.replace(0, position_of_blank+1, "");
			position_of_blank = sentence.find(' ');
			number_of_words++;
		}
		list.Insert(sentence, number_of_words);
		number_of_words++;
		return number_of_words;
}
