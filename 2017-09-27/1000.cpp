#include <iostream>
#include"ListNode.h"
#include <list>
using namespace std;
    std::list<int> toStdLit(ListNode* mylst) {
        std::list<int> ret;
        while(mylst!=NULL) {
            ret.push_back(mylst->val);
            mylst = mylst->next;
        }
        return ret;
    }
    ListNode* toMyList(std::list<int> stdlst) {
        ListNode* head;
        if(stdlst.size() != 0)
        {
            head->val = stdlst.front();
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
    for(auto it = stdlst.begin(); it != stdlst.end();) {
        l2.push_back(*it);
    }
    cout << "--------" << endl;
    for(auto i : l2)
        cout << i << endl;
    cout << "--------" << endl;
    auto mylst = toMyList(l2);
    return mylst;
}


