class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(const auto& t: times) {
            adj[t[0]].emplace_back(t[1], t[2]);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, INT_MAX);

        dist[k] = 0;
        pq.push({0, k});
        
        while(!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if(time > dist[node]) continue;

            for(const auto& [neighbor, weight]: adj[node]) {
                if(dist[node] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[node] + weight;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

        int total = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX) return -1;
            total = max(total, dist[i]);
        }
        return total;
    }
};
