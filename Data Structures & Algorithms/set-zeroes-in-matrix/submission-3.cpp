class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool rowZero = false;

        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(matrix[r][c] == 0) {
                    matrix[0][c] = 0;
                    if(r > 0) {
                        matrix[r][0] = 0;
                    } else {
                        rowZero = true;
                    }
                }
            }
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
            }
        }

        if(matrix[0][0] == 0) for(int r = 0; r < m; r++) matrix[r][0] = 0;
        if(rowZero) for(int j = 0; j < n; j++) matrix[0][j] = 0;
    }
};
