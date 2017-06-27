#ifndef _LIST_ADD_
#define _LIST_ADD_

#include <iostream>
using std::string;
using std::ostream;
class List {
private:
	struct node {
		int val;
		node* next;
		node(int v, node* n = 0) :val(v), next(n) {}
	};
	node* head;
	int _size;
public:
	List();
	List(const List& other);
	List(const string & num);
	void clear();
	void push_front(int val);   // ��ͷ��������ֵ
	List operator+(const List& other);    //�������������ӷ�ʵ��
	List& operator=(const List& other);   // ��ֵ��������
	int size() const;
	~List();
	friend ostream& operator<<(ostream & os, const List &  out);
	// ������֣����軻��
};
#endif
