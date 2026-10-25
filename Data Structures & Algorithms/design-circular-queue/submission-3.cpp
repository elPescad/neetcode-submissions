class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class MyCircularQueue {
public:
    int curr;
    Node* head;
    Node* tail;
    MyCircularQueue(int k) {
        head = new Node(0);
        tail = head;
        curr = k;
    }
    
    bool enQueue(int value) {
        if(!isFull()) {
            tail->next = new Node(value);
            Node* hold = tail;
            tail = tail->next;
            tail->prev = hold;
            curr--;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(!isEmpty()) {
            head = head->next;
            head->val = 0;
            head->prev = nullptr;
            curr++;
            return true;
        }
        return false;
    }
    
    int Front() {
        if(!isEmpty()) return head->next->val;
        return -1;
    }
    
    int Rear() {
        if(!isEmpty()) return tail->val;
        return -1;
    }
    
    bool isEmpty() {
        return head->next == nullptr;
    }
    
    bool isFull() {
        return curr == 0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */