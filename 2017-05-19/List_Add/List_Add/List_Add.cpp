// List_Add.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include "ListAdd.hpp"
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

List::List()
	: head(NULL)
	, _size(0)
{
}
List::List(const List& other)
	: head(NULL)
	, _size(0)
{
	if (other.head == NULL)
		return;
	using list_iterator = node*;
	head = new node(*other.head);
	list_iterator this_it = this->head;
	_size++;
	for (list_iterator it = other.head->next; it != NULL; it = it->next) {
		this_it->next = new node(*it);
		this_it = this_it->next;
		_size++;
	}
}
List::List(const string& num)
	: head(NULL)
	, _size(0)
{
	if (num.empty())
		return;
	using list_iterator = node*;
	head = new node(*num.crbegin() - '0');
	_size++;
	list_iterator this_it = this->head;
	for (auto it = num.crbegin() + 1; it != num.crend(); ++it) {
		this_it->next = new node(*it - '0');
		this_it = this_it->next;
		_size++;
	}
}
void List::clear()
{
	using list_iterator = node*;
	list_iterator this_it = this->head;
	while (this_it != NULL) {
		list_iterator tmp = this_it->next;
		delete this_it;
		this_it = tmp;
	}
	_size = 0;
}

void List::push_front(int val)
{
	node* tmp = new node(val, head);
	head = tmp;
}
List List::operator+(const List& other)
{
	using list_iterator = node*;
	const int add_bits = min(_size, other._size);
	const int bits = max(_size, other._size);
	string ans;
	int addon = 0;
	list_iterator this_it = head;
	list_iterator other_it = other.head;
	for (int i = 0; i < bits; ++i) {
		int this_bit = 0;
		if (i < add_bits)
			this_bit = this_it->val + other_it->val + addon;
		else if (_size > other._size)
			this_bit = this_it->val + addon;
		else
			this_bit = other_it->val + addon;
		if (this_bit > 9) {
			addon = 1;
			ans.push_back(static_cast<char>(this_bit - 10 + '0'));
		}
		else {
			addon = 0;
			ans.push_back(static_cast<char>(this_bit + '0'));
		}
		if (i < add_bits) {
			this_it = this_it->next;
			other_it = other_it->next;
		}
		else if (_size > other._size)
			this_it = this_it->next;
		else
			other_it = other_it->next;
	}
	if(addon == 1)
		ans.push_back('1');
	reverse(ans.begin(), ans.end());
	return List(ans);
}

List& List::operator=(const List& other)
{
	List tmp(other);
	_size = tmp._size;
	head = tmp.head;
	tmp.head = NULL;
	return *this;
}

int List::size() const
{
	return _size;
}
List::~List()
{
	clear();
}
ostream& operator<<(ostream& os, const List& out)
{
	stringstream ss;
	using list_iterator = List::node*;
	for (list_iterator it = out.head; it != NULL; it = it->next)
		ss << it->val;
	string s = ss.str();
	reverse(s.begin(), s.end());
	os << s;
	return os;
}


