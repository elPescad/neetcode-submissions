class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, false));
        vector<vector<int>> atlantic(m, vector<int>(n, false));

        for(int r = 0; r < pacific.size(); r++) {
            traverse(pacific, heights, r, 0, heights[r][0]);
        }
        for(int c = 0; c < pacific[0].size(); c++) {
            traverse(pacific, heights, 0, c, heights[0][c]);
        }

        for(int r = 0; r < atlantic.size(); r++) {
            traverse(atlantic, heights, r, n-1, heights[r][n-1]);
        }
        for(int c = 0; c < pacific[0].size(); c++) {
            traverse(atlantic, heights, m-1, c, heights[m-1][c]);
        }

        vector<vector<int>> res;
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(pacific[r][c] && atlantic[r][c]) {
                    res.push_back({r,c});
                }
            }
        }

        return res;
    }

    void traverse(vector<vector<int>>& ocean, vector<vector<int>>& heights, int r, int c, int prev) {
        if(r >= 0 && r < ocean.size() && c >= 0 && c < ocean[r].size()) {
            if(ocean[r][c] == true || heights[r][c] < prev) {
                return;
            }

            ocean[r][c] = true;

            traverse(ocean, heights, r+1, c, heights[r][c]);
            traverse(ocean, heights, r-1, c, heights[r][c]);
            traverse(ocean, heights, r, c+1, heights[r][c]);
            traverse(ocean, heights, r, c-1, heights[r][c]);
        }
    }
};
