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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* difference = head;

        for(int i = 0; i < n; i++) {
            difference = difference->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(difference != nullptr) {
            prev = curr;
            curr = curr->next;
            difference = difference->next;
        }

        if(prev != nullptr) {
            prev->next = curr->next;
        } else {
            head = curr->next;
        }

        return head;
    }
};
