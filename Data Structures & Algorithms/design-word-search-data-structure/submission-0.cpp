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
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }

    bool searchHelper(int index, const string& word, Node* node) {
        if(index == word.length()) {
            return node->isEnd;
        }

        if(word[index] == '.') {
            for(int i = 0; i < 26; i++) {
                if(node->alpha[i]) {
                    if(searchHelper(index+1, word, node->alpha[i])) {
                        return true;
                    }
                }
            }
            return false;
        } else {
            int val = word[index] - 'a';
            if(!node->alpha[val]) {
                return false;
            }

            return searchHelper(index+1, word, node->alpha[val]);
        }
    }
    
    void addWord(string word) {
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
        return searchHelper(0, word, root);
    }
};
