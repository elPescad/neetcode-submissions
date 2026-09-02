class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c] == 2) {
                    q.push({r, c});
                } else if( grid[r][c] == 1) {
                    fresh++;
                }
            }
        }
        
        vector<vector<int>> direct = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int count = 0;
        while(!q.empty() && fresh > 0) {
            int sze = q.size();

            for(int i = 0; i < sze; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int j = 0; j < 4; j++) {
                    int rT = r + direct[j][0];
                    int cT = c + direct[j][1];

                    if(rT < 0 || rT >= m || cT < 0 || cT >= n || grid[rT][cT] != 1) {
                        continue;
                    }

                    grid[rT][cT] = 2;
                    q.push({rT, cT});
                    fresh--;
                }
            }
            count++;
        }
        return fresh == 0 ? count : -1;
    }
};
