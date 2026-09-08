class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        set<pair<int, int>> visit;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        pq.push({grid[0][0], 0, 0});
        visit.insert({0,0});

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int t = curr[0], r = curr[1], c = curr[2];
            if(r == n-1 && c == n-1) {
                return t;
            }
            for(const auto& dir: directions) {
                int cR = r + dir[0], cT = c + dir[1];
                if(cR < 0 || cT < 0 || cR == n || cT == n || visit.contains({cR, cT})) {
                    continue;
                } 

                visit.insert({cR, cT});
                pq.push({max(t, grid[cR][cT]), cR, cT});
            }
        }

        return 1;
    }
};
