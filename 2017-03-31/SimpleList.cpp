#include <vector>
#include <algorithm>
#include <sstream>
#include "SimpleList.hpp"
list::list() : head(NULL), _size(0) { }

using list_iterator = node*;
using const_list_iterator = const node*;

list::list(const list& rhs) 
{
    _size = rhs._size;
    const_list_iterator rhs_iter = rhs.head;
    if(rhs_iter != NULL)
        head = new node(rhs_iter->data);
    rhs_iter = rhs_iter->next;
    list_iterator this_iter = head;
    while (rhs_iter != NULL) {
        this_iter->next = new node(rhs_iter->data);
        rhs_iter = rhs_iter->next;
        this_iter = this_iter->next;
    }
}

bool list::empty() const {
    node * n = new node;
    return !_size;
}

void list::insert(int position, const int& data)
{
    list_iterator iter = this->head;
    if(position > _size) 
        return;
    else {
        if(head == NULL) 
            head = new node(data);
        else if(position == 0) {
            node* tmp = new node(data);
            tmp->next = head;
            head = tmp;
        }
        else {
            for(int i = 0; i < position - 1; ++i)
               iter = iter->next;
            node* tmp = new node(data);
            if (iter != NULL) {
                tmp->next = iter->next;
                iter->next = tmp;
            }
        }
        ++_size;
    }
} 

list::~list() {
    list_iterator iter = this->head;
    while(iter != NULL) {
        list_iterator tmp = iter->next;
        delete iter;
        iter = tmp;
    }
}

void list::erase(int position) {
    list_iterator iter = this->head;
    if(position >= _size)
        return;
    else {
        if(position == 0) {
            delete head;
            head = iter->next;
        }
        else {
            for(int i = 0; i < position - 1; ++i)
               iter = iter->next;
            list_iterator tmp = iter->next;
            iter->next = tmp->next;
            delete tmp;
        }
        --_size;
    }
}

list& list::operator=(const list& rhs) {
    if (this == &rhs) return *this;
    list_iterator iter = this->head;
    while(iter != NULL) {
        list_iterator tmp = iter->next;
        delete iter;
        iter = tmp;
    }
    _size = rhs._size;
    const_list_iterator rhs_iter = rhs.head;
    if(rhs_iter != NULL)
        head = new node(rhs_iter->data);
    rhs_iter = rhs_iter->next;
    list_iterator this_iter = head;
    while (rhs_iter != NULL) {
        this_iter->next = new node(rhs_iter->data);
        rhs_iter = rhs_iter->next;
        this_iter = this_iter->next;
    }
    return *this;
}

list& list::sort(void) {
    std::vector<int> vec;
    const_list_iterator citer = head;
    while(citer != NULL) {
        vec.push_back(citer->data);
        citer = citer->next;
    }
    std::sort(vec.begin(), vec.end());
    list_iterator iter = head;
    for(int i = 0; iter != NULL; ++i, iter = iter->next)
        iter->data = vec[i];
    return *this;
}


std::string list::toString(void) const {
    const_list_iterator citer = head;
    std::stringstream ss;
    while(citer != NULL) {
        ss << citer->data;
        ss << "->";
        citer = citer->next;
    }
    ss << "NULL";
    return ss.str();
}

int list::size() const {
    return _size;
}
