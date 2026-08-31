class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int r = 0; r < grid.size(); r++) {
            for(int c = 0; c < grid[r].size(); c++) {
                if(grid[r][c] == '1') {
                    traverse(grid, r, c);
                    count++;
                }
            }
        }
        return count;
    }

    void traverse(vector<vector<char>>& grid, int r, int c) {
        if(r >= 0 && r < grid.size() && c >= 0 && c < grid[r].size()) {
            if(grid[r][c] == '0') {
                return;
            } else {
                grid[r][c] = '0';
            }

            traverse(grid, r+1, c);
            traverse(grid, r-1, c);
            traverse(grid, r, c+1);
            traverse(grid, r, c-1);
        }
    }
};
