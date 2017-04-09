#include "SimpleList.hpp" 
#include <string>
#include <iostream>
using namespace std;

string itos(int a){
	string b;
	while(a != 0){
		char temp = a % 10 + '0';
		b += temp;
		a /= 10;
	}
	return b;
}

list::list(){
	head = NULL;
	_size = 0;
}

list::list(const list& a){
	_size = a._size;
	node *p = new node;
	p = a.head;
	node *n, *b;
	head = p;
	n = a.head;
	b = p;
	while(n -> next != NULL){
		n = n -> next;
		node *m = new node;
		m = n;
		b -> next = m;
		b = m;
	}
	cout << a.toString() << endl;
}

list& list::operator = (const list& a){
	if(head != a.head){
		node *p = head;
		node *n;
		for(int i = 0; i < _size; i ++){
			n = p -> next;
			delete p;
			p = n;
		}
	}
	_size = a._size;
	head = a.head;
	return *this;
}

list::~list(){
	node *p = head;
	node *n;
	for(int i = 0; i < _size; i ++){
		n = p -> next;
		delete p;
		p = n;
	}
}

bool list::empty() const{
	if(head == NULL) return 1;
	else return 0;
}

int list::size() const{
	return _size;
}

string list::toString() const{
	node *p = new node;
	p = head;
	string a = itos(p -> data);
	string b = "->";
	while(p -> next != NULL){
		p = p -> next;
		a = a + b;
		a = a + itos(p -> data);
	}
	a += "->NULL";
	delete p;
	return a;
}

void list::insert(int position, const int & data){
	node *p = new node(data);
	node *n;
	if(position > _size) return;
	if(_size == 0){
		head = p;
		_size ++;
		return;
	}
	node *m = head;
	for(int i = 1; i < position; i ++){
		m = m -> next;
	}
	n = m -> next;
	m -> next = p;
	p -> next = n;
	_size ++;
}

void list::erase(int position){
	if(_size == 0) return;
	node * m = head;
	node *n;
	for(int i = 0; i < position; i ++){
		m = m -> next;
	}
	n = m -> next -> next;
	node *temp = m -> next;
	delete temp;
	m -> next = n;
}

list& list::sort(){
	if(_size == 0) return *this;
	for(int x = 0; x < _size; x ++){
		node *p = head;
		for(int i = 0; i < x; i ++){
			p = p -> next;
		}
		int max = p -> data;
		while(p -> next != NULL){
			p = p -> next;
			if(max < p -> data) max = p -> data;
		}
		node *temp = head;
		for(int i = 0; i < _size; i ++){
			if(temp -> data == max){
				node *n = head;
				head = temp;
				head -> next = n;
				break;
			}
			temp = temp -> next;
		}
	}
	return *this;
}
