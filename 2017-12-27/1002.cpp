#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <utility>
#include <vector>
using namespace std;

struct ListNode
{
int val;
ListNode * next;
ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    ListNode* head = nullptr;
    ListNode* n = head;
    size_t nullcnt = 0;
    while(!(nullcnt == lists.size())) {
        vector<ListNode*>::iterator ptr = std::min_element(lists.begin(), lists.end(), [](auto l1, auto l2) {
                // nullptr is considered as inf
                return (l1 != nullptr && l2 != nullptr) ? l1->val < l2 -> val :
                        l1 == nullptr ? false :
                        true;
                });
        if(*ptr == nullptr)
            break;
        else {
            if(head == nullptr) {
                head = new ListNode((*ptr)->val);
                n = head;
            }
            else {
                n->next = new ListNode((*ptr)->val);
                n = n->next;
            }
            (*ptr) = (*ptr)->next;
            if((*ptr) == nullptr)
                nullcnt++;
        }
    }
    return head;
}


