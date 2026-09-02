class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int rT = r + directions[i][0];
                int cT = c + directions[i][1];

                if(rT < 0 || rT >= m || cT < 0 || cT >= n || grid[rT][cT] != INT_MAX) {
                    continue;
                }

                grid[rT][cT] = grid[r][c] + 1;
                q.push({rT, cT});
            }
        }
    }
};
