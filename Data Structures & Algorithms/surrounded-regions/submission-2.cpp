class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        vector<vector<bool>> check(m, vector<bool>(n, false));

        for(int r = 0; r < m; r++) traverse(check, board, r, 0);
        for(int c = 0; c < n; c++) traverse(check, board, 0, c);

        for(int r = 0; r < m; r++) traverse(check, board, r, n-1);
        for(int c = 0; c < n; c++) traverse(check, board, m-1, c);

        for(int r = 0; r < board.size(); r++) {
            for(int c = 0; c < board[r].size(); c++) {
                if(!check[r][c]) {
                    board[r][c] = 'X';
                }
            }
        }
    }

    void traverse(vector<vector<bool>>& check, vector<vector<char>>& board, int r, int c) {
        if(r >= 0 && r < board.size() && c >= 0 && c < board[0].size()) {
            if(board[r][c] == 'X' || check[r][c]) {
                return;
            }

            check[r][c] = true;

            traverse(check, board, r+1, c);
            traverse(check, board, r-1, c);
            traverse(check, board, r, c+1);
            traverse(check, board, r, c-1);
        }
    }
};
