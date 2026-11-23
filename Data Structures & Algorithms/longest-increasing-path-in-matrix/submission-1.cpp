class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        int maxVal = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                maxVal = max(traverse(res, matrix, i, j), maxVal);
            }
        }
        return maxVal;
    }

    int traverse(vector<vector<int>>& res, vector<vector<int>>& matrix, int r, int c) {
        if(res[r][c] != 0) return res[r][c];

        int best = 1;
        for(auto& d : dir) {
            int nr = r + d[0];
            int nc = c + d[1];
            if(nr >= 0 && nr < matrix.size() && nc >= 0 && nc < matrix[0].size() && matrix[nr][nc] > matrix[r][c]) {
                best = max(best, 1+traverse(res, matrix, nr, nc));
            }
        }

        res[r][c] = best;
        return best;
    }
};
