/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int getNum(ListNode* l) {
        int ret = 0;
        while(l) {
            ret = ret * 10 + l->val;
            l = l->next;
        }
        return ret;
    }
    ListNode* makeList(int num) {
        ListNode* ret = new ListNode(num % 10); //个位
        num /= 10;
        ListNode* cur = ret;
        while(num) {
            cur->next = new ListNode(num % 10);
            cur = cur->next;
            num /= 10;
        }
        return ret;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto ans = getNum(l1) + getNum(l2);
        return makeList(ans);
    }
};
