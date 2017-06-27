#include "ListAdd.hpp"
#include <algorithm>
#include <string>
using namespace std;

List::List()
    : head(NULL)
    , _size(0)
{
}
List::List(const List& other)
    : head(NULL)
    , _size(other._size)
{
    if(other.head == NULL)
        return;
    using list_iterator = node*;
    head = new node(*other.head);
    list_iterator this_it = this->head;
    for (list_iterator it = other.head -> next; it != NULL; it = it->next) {
        this_it->next = new node(*it);
        this_it = this_it ->next;
        _size++;
    }
}
List::List(const string& num)
    : head(NULL)
    , _size(0)
{
    if(num.empty())
        return;
    using list_iterator = node*;
    head = new node(*num.crbegin() - '0');
    list_iterator this_it = this->head;
    for (auto it = num.crbegin() + 1; it != num.crend(); ++it) {
        this_it->next = new node(*it - '0');
        this_it = this_it ->next;
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
    int addon = 0;
    string ans;
    list_iterator this_it = head;
    list_iterator other_it = other.head;
    for (int i = 0; i < bits; ++i) {
        int this_bit = 0;
        if (i < add_bits)
            this_bit = this_it->val + other_it->val + addon;
        else
            this_bit = this_it->val + addon;
        if (this_bit > 9) {
            addon = 1;
            ans.push_back(static_cast<char>(this_bit - 10 + '0'));
        } else {
            addon = 0;
            ans.push_back(static_cast<char>(this_bit + '0'));
        }
    }
    reverse(ans.begin(), ans.end());
    return List(ans);
}

List& List::operator=(const List& other)
{
    List tmp(other);
    swap(tmp, *this);
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
    using list_iterator = List::node*;
    for (list_iterator it = out.head; it != NULL; it = it->next)
        os << it->val;
    return os;
}

