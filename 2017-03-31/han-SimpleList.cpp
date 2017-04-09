#include "SimpleList.hpp"
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
list& list::sort()
{
    list* p = new list();
    p->_size = _size;
    int size = _size;
    for (int i = 0; i < size; i++) {
        int min = 99999999;
        int num = 0;
        node* q = this->head;
        node* t = q;
        for (int j = 0; j < _size && t != NULL; j++) {
            if (q->data < min) {
                min = q->data;
                num = j;
            }
            t = q;
            q = q->next;
        }
        p->insert(i, min);
        (*this).erase(num);
    }
    (*this).clear();
    *this = *p;
    p->clear();
    return *this;
}
list& list::operator=(const list& x)
{
    if (this->head != NULL)
        return *this;
    node* p = x.head;
    node* p1 = p->next;
    this->head = NULL;
    this->_size = x._size;
    while (p != NULL) {
        node* t = new node();
        t->next = p->next;
        p->next = t;
        t->data = p->data;
        p = p1;
        if (p1 == NULL)
            break;
        p1 = p1->next;
    }
    this->head = x.head->next;
    p = x.head;
    p1 = x.head->next;
    while (p1 != NULL) {
        p->next = p1->next;
        if (p1->next == NULL)
            break;
        p1->next = p->next->next;
        p = p->next;
        p1 = p1->next;
    }
    return *this;
}
void list::erase(int pos)
{
    if (pos >= _size)
        return;
    if (!pos) {
        node* p = this->head;
        this->head = this->head->next;
        delete p;
    } else {
        int size = 0;
        node* p = this->head;
        while (size <= pos - 2) {
            p = p->next;
            size++;
        }
        node* temp = p->next;
        p->next = temp->next;
        delete temp;
    }
    _size--;
}
void list::insert(int pos, const int& d)
{
    if (pos > _size)
        return;
    if (!pos) {
        node* p = new node(d, head);
        this->head = p;
    } else {
        node* p = this->head;
        int size = 0;
        while (size <= pos - 2) {
            p = p->next;
            size++;
        }
        node* q = new node(d, p->next);
        p->next = q;
    }
    _size++;
    node* p = this->head;
    while (p != NULL) {
        //		cout<<p->data<<endl;
        p = p->next;
    }
}
string list::toString() const
{
    string s;
    if (this->head == NULL) {
        s = "NULL";
        return s;
    }
    node* p = this->head;
    s = to_string(p->data);
    while (p != NULL) {
        s += "->";
        p = p->next;
        if (p == NULL)
            break;
        s += to_string(p->data);
    }
    s += "NULL";
    return s;
}
list::list()
{
    this->head = NULL;
    this->_size = 0;
}
list::list(const list& x)
{
    node* p = x.head;
    node* p1 = p->next;
    this->head = NULL;
    this->_size = x._size;
    while (p != NULL) {
        node* t = new node();
        t->next = p->next;
        p->next = t;
        t->data = p->data;
        p = p1;
        if (p1 == NULL)
            break;
        p1 = p1->next;
    }
    this->head = x.head->next;
    p = x.head;
    p1 = x.head->next;
    while (p1 != NULL) {
        p->next = p1->next;
        if (p1->next == NULL)
            break;
        p1->next = p->next->next;
        p = p->next;
        p1 = p1->next;
    }
}

list::~list()
{
    node* p = this->head;
    while (p != NULL) {
        node* t = p->next;
        delete p;
        p = t;
    }
    _size = 0;
}
bool list::empty() const
{
    if (!_size)
        return 0;
    else
        return 1;
}
int list::size() const
{
    return _size;
}

