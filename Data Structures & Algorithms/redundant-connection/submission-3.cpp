class Solution {
public:
    int cycleStart;
    unordered_set<int> cycle;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>> graph(m+1);
        vector<int> visited(m+1, false);

        for(int i = 0; i < m; i++) {
            int first = edges[i][0];
            int second = edges[i][1];
            graph[first].push_back(second);
            graph[second].push_back(first);
        }
        cycleStart = -1;
        traverse(1, -1, graph, visited);

        for(int i = m-1; i >= 0; i--) {
            int first = edges[i][0];
            int second = edges[i][1];
            if(cycle.contains(first) && cycle.contains(second)) {
                return {first, second};
            }
        }
        return {};
    }

    bool traverse(int curr, int parent, vector<vector<int>>& graph, vector<int>& visited) {
        if(visited[curr]) {
            cycleStart = curr;
            return true;
        }
        visited[curr] = true;
        for(int neighbor: graph[curr]) {
            if(neighbor == parent) continue;
            if(traverse(neighbor, curr, graph, visited)) {
                if(cycleStart != -1) cycle.insert(curr);
                if(curr == cycleStart) cycleStart = -1;
                return true;
            }
        }
        return false;
    }
};