class Solution {
public:
    unordered_set<int> cols;
    unordered_set<int> pos;
    unordered_set<int> neg;
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        traverse(0, n, board);
        return res;
    }

    void traverse(int r, int& n, vector<string>& board) {
        if(r == n) {
            res.push_back(board);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(cols.contains(i) || pos.contains(r+i) || neg.contains(r-i)) {
                continue;
            }

            cols.insert(i);
            pos.insert(r+i);
            neg.insert(r-i);
            board[r][i] = 'Q';

            traverse(r+1, n, board);

            cols.erase(i);
            pos.erase(r+i);
            neg.erase(r-i);
            board[r][i] = '.';
        }
    }
};
