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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr) {
            ListNode* future = curr;
            for(int i = 0; i < k-1; i++) {
                future = future->next;
                if(!future) return dummy->next;
            }

            ListNode* grab = future->next;
            future->next = nullptr;

            reverse(curr);

            prev->next = future;
            curr->next = grab;

            prev = curr;
            curr = grab;
        }

        return dummy->next;
    }

    void reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while(head != nullptr) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
    }
};
