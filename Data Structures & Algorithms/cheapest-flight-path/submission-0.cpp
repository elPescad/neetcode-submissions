class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> airports(n);
        vector<int> graph(n, INT_MAX);
        graph[src] = 0;

        for(vector<int>& f: flights) {
            airports[f[0]].push_back({f[1], f[2]});
        }

        queue<tuple<int, int, int>> q;

        q.push({0, src, 0});

        while(!q.empty()) {
            auto [cst, node, stops] = q.front();
            q.pop();
            if(stops > k) continue;

            for(const auto& neighbor : airports[node]) {
                int nei = neighbor.first, w = neighbor.second;
                int nextCost = cst + w;
                if(nextCost < graph[nei]) {
                    graph[nei] = nextCost;
                    q.push({nextCost, nei, stops + 1});
                }
            }
        }
        return graph[dst] == INT_MAX ? -1 : graph[dst];
    }
};
