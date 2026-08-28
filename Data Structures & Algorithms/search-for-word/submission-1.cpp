class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int r = 0; r < board.size(); r++) {
            for(int c = 0; c < board[r].size(); c++) {
                if(board[r][c] == word[0]) {
                    if(foundWord(board, word, r, c, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool foundWord(vector<vector<char>>& board, const string& word, int r, int c, int i) {
        if(i == word.size()) {
                return true;
        }

        if(r >= 0 && r < board.size() && c >= 0 && c < board[r].size()) {
            if(board[r][c] != word[i]) {
                return false;
            }

            char temp = board[r][c];
            board[r][c] = '#';
            
            bool left = foundWord(board, word, r, c-1, i+1);
            bool right = foundWord(board, word, r, c+1, i+1);
            bool up = foundWord(board, word, r-1, c, i+1);
            bool down = foundWord(board, word, r+1, c, i+1);

            board[r][c] = temp;

            return left || right || up || down;
        }
        return false;
    }
};