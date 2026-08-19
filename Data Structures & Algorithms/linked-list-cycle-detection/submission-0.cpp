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
    bool hasCycle(ListNode* head) {
        while(head != nullptr) {
            if(head->val == INT_MIN) {
                return true;
            }
            head->val = INT_MIN;
            head = head->next;
        }
        return false;
    }
};
