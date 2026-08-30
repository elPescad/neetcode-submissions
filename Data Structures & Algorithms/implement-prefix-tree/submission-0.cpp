class Node {
public:
    Node* alpha[26];
    bool isEnd;

    Node() {
        isEnd = false;
        for(int i = 0; i < 26; i++) {
            alpha[i] = nullptr;
        }
    }
};
class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(const char& c: word) {
            int val = c - 'a';
            if(!curr->alpha[val]) {
                curr->alpha[val] = new Node();
            }
            curr = curr->alpha[val];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(const char& c: word) {
            int val = c - 'a';
            if(!curr->alpha[val]) {
                return false;
            }
            curr = curr->alpha[val];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(const char& c: prefix) {
            int val = c - 'a';
            if(!curr->alpha[val]) {
                return false;
            }
            curr = curr->alpha[val];
        }
        return true;
    }
};
