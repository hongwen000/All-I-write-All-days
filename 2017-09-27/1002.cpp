#include <iostream>
#include <list>
using namespace std;
#include"ListNode.h"
    std::list<int> toStdLit(ListNode* mylst) {
        std::list<int> ret;
        auto it = mylst;
        while(it!=NULL) {
            ret.push_back(it->val);
            it = it->next;
        }
        return ret;
    }
    ListNode* toMyList(std::list<int> stdlst) {
        ListNode* head;
        if(stdlst.size() != 0)
        {
          	head = new ListNode(stdlst.front());
            if(stdlst.size() != 1) {
                auto iter = head;
                for(auto it = ++(stdlst.begin()); it != stdlst.end(); ++it) {
                    iter->next = new ListNode(*it);
                    iter = iter->next;
                }
            }
        }
        return head;
    }
ListNode* partList(ListNode* head, int x) {
    auto stdlst = toStdLit(head);
    list<int> l2;
    for(auto it = stdlst.begin(); it != stdlst.end();) {
        if(*it < x) {
            l2.push_back(*it);
            it = stdlst.erase(it);
        }
        else {
            ++it;
        }
    }
    for(auto it = stdlst.begin(); it != stdlst.end();++it) {
        l2.push_back(*it);
    }
    auto mylst = toMyList(l2);
    return mylst;
}

ListNode* resetList(ListNode* head) {
    auto stdlst = toStdLit(head);
    list<int> l2;
    int pos = 0;
    for(auto it = stdlst.begin(); it != stdlst.end();) {
        if(pos % 2 == 0) {
            l2.push_back(*it);
            it = stdlst.erase(it);
        }
        else {
            ++it;
        }
        ++pos;
    }
    for(auto it = stdlst.begin(); it != stdlst.end();++it) {
        l2.push_back(*it);
    }
    auto mylst = toMyList(l2);
    return mylst;
}

ListNode* reverseList(ListNode* head){
    auto stdlst = toStdLit(head);
    std::reverse(head.begin(), head.end());
    auto ret=toMyList(stdlst);
    return ret;
}

