class Trie{
public:
    unordered_map<char, Trie*> children;
    bool isWord;

    Trie() {
        isWord = false;
    }

    void addWord(const string& word) {
        Trie* curr = this;
        for(char c: word) {
            if(!curr->children.contains(c)) {
                curr->children[c] = new Trie();
            }
            curr = curr->children[c];
        }
        curr->isWord = true;
    }
};
class Solution {
public:
    unordered_set<string> res;
    vector<vector<bool>> visit;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        for(const string& word: words) {
            root->addWord(word);
        }

        int rows = board.size(), cols = board[0].size();
        visit.assign(rows, vector<bool>(cols, false));

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                dfs(board, r, c, root, "");
            }
        }
        return vector<string>(res.begin(), res.end());
    }

    void dfs(vector<vector<char>>& board, int r, int c, Trie* node, string word) {
        int rows = board.size(), cols = board[0].size();
        if(r < 0 || c < 0 || r >= rows || c >= cols || visit[r][c] || !node->children.contains(board[r][c])) {
            return;
        }

        visit[r][c] = true;
        node = node->children[board[r][c]];
        word += board[r][c];
        if(node->isWord) {
            res.insert(word);
        }

        dfs(board, r+1, c, node, word);
        dfs(board, r-1, c, node, word);
        dfs(board, r, c+1, node, word);
        dfs(board, r, c-1, node, word);

        visit[r][c] = false;
    }
};
