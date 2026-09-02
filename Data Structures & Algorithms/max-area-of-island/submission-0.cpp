class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx = 0;
        for(int r = 0; r < grid.size(); r++) {
            for(int c = 0; c < grid[r].size(); c++) {
                if(grid[r][c] == 1) {
                    int count = 0;
                    traverse(grid, r, c, count);
                    mx = max(mx, count);
                }
            }
        }
        return mx;
    }

    void traverse(vector<vector<int>>& grid, int r, int c, int& count) {
        if(r >= 0 && r < grid.size() && c >= 0 && c < grid[r].size()) {
            if(grid[r][c] == 0) {
                return;
            } else {
                count++;
                grid[r][c] = 0;
            }

            traverse(grid, r+1, c, count);
            traverse(grid, r-1, c, count);
            traverse(grid, r, c+1, count);
            traverse(grid, r, c-1, count);
        }
    }
};
