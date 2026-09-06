class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>> graph(m+1);

        for(int i = 0; i < m; i++) {
            int first = edges[i][0];
            int second = edges[i][1];
            graph[first].push_back(second);
            graph[second].push_back(first);

            vector<int> visited(m+1, false);

            if(traverse(first, -1, graph, visited)) {
                return {first, second};
            }
        }
        return {};
    }

    bool traverse(int curr, int parent, vector<vector<int>>& graph, vector<int>& visited) {
        if(visited[curr]) return true;
        visited[curr] = true;

        for(int neighbor: graph[curr]) {
            if(neighbor == parent) continue;
            if(traverse(neighbor, curr, graph, visited)) return true;
        }
        return false;
    }
};
