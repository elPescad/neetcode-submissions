class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    // 1   5   9   13
    // 2   6   10  14
    // 3   7   11  15
    // 4   8   12  16
};
