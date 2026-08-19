/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> seen;
        Node* dummyHead = new Node(0);
        Node* curr = head;
        Node* res = dummyHead;

        while(curr != nullptr) {
            dummyHead->next = new Node(curr->val);
            seen[curr] = dummyHead->next;
            curr = curr->next;
            dummyHead = dummyHead->next; 
        }

        curr = head;
        dummyHead = res->next;

        while(curr != nullptr) {
            dummyHead->random = seen[curr->random];
            curr = curr->next;
            dummyHead = dummyHead->next;
        }

        return res->next;
    }
};
