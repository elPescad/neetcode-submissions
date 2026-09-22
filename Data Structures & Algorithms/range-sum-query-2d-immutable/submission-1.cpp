class NumMatrix {
public:
    vector<vector<int>> sums;
    NumMatrix(vector<vector<int>>& matrix) {
        sums.resize(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i < matrix.size(); i++) {
            sums[i][0] = matrix[i][0];
            for(int j = 1; j < matrix[i].size(); j++) {
                sums[i][j] = sums[i][j-1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for(int row = row1; row <= row2; row++) {
            if(col1 > 0) {
                res += sums[row][col2] - sums[row][col1-1];
            } else {
                res += sums[row][col2];
            }
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */