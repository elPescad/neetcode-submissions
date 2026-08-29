class Solution {
public:
    vector<bool> cols, pos, neg;
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        cols.resize(n, false);
        pos.resize(2*n, false);
        neg.resize(2*n, false);
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
            if(cols[i] || pos[r+i] || neg[r-i+n]) {
                continue;
            }

            cols[i] = true;
            pos[r+i] = true;
            neg[r-i+n] = true;
            board[r][i] = 'Q';

            traverse(r+1, n, board);

            cols[i] = false;
            pos[r+i] = false;
            neg[r-i+n] = false;
            board[r][i] = '.';
        }
    }
};
