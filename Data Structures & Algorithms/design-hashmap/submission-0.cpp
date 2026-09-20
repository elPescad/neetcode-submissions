class ListNode {
public:
    int key;
    int val;
    ListNode* next;

    ListNode(int k) {
        key = k;
        val = -1;
        next = nullptr;
    }
};
class MyHashMap {
public:
    vector<ListNode*> mp;

    MyHashMap() {
        mp.resize(10000);
        for(auto& bucket: mp) {
            bucket = new ListNode(0);
        }
    }

    int hash(int key) {
        return key % mp.size();
    }
    
    void put(int key, int value) {
        ListNode* curr = mp[hash(key)];

        while(curr->next) {
            if(curr->next->key == key) {
                if(curr->next->val == value) {
                    return;
                }
                curr->next->val = value;
                return;
            }
            curr = curr->next;
        }
        curr->next = new ListNode(key);
        curr->next->val = value;
    }
    
    int get(int key) {
        ListNode* curr = mp[hash(key)];
        while(curr->next) {
            if(curr->next->key == key) {
                return curr->next->val;
            }
            curr = curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        ListNode* curr = mp[hash(key)];
        while(curr->next) {
            if(curr->next->key == key) {
                ListNode* temp = curr->next;
                curr->next = temp->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */