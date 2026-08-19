/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = l1;
        ListNode* prev = nullptr;
        int one = 0;
        while(l1 && l2) {
            int sum = l1->val + l2->val + one;
            if(sum/10>0) {
                one = 1;
            } else {
                one = 0;
            }

            l1->val = sum%10;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1) {
            int sum = l1->val + one;
            if(sum/10>0) {
                one = 1;
            } else {
                one = 0;
            }
            l1->val = sum%10;
            prev = l1;
            l1 = l1->next;
        }

        if(l2) prev->next = l2;
        while(l2) {
            int sum = l2->val + one;
            if(sum/10>0) {
                one = 1;
            } else {
                one = 0;
            }
            l2->val = sum%10;
            prev = l2;
            l2 = l2->next;
        }

        if(one != 0) {
            while(prev->next) {
                prev = prev->next;
            }

            prev->next = new ListNode(1);
        }

        return res;
    }
};
