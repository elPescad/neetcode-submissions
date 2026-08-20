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
        ListNode* curr = head;
        ListNode* future = head;
        ListNode* res = curr;
        ListNode* prev = nullptr;

        while(future) {
            for(int i = 0; i < k-1; i++) {
                future = future->next;
                if(!future) {
                    return res;
                }
            }
            ListNode* grab = future->next;
            future->next = nullptr;
            ListNode* copy = curr;
            reverse(copy);

            if(prev) {
                prev->next = future;
            } else {
                res = future;
            }

            curr->next = grab;
            prev = curr;

            curr = grab;
            future = grab;
        }

        return res;
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
