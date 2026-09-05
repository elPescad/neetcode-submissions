class Solution {
public:
    int countEdges = 0;
    bool validTree(int n, vector<vector<int>>& edges) {
        int m = edges.size();

        vector<bool> visited(n, false);
        vector<vector<int>> connected(n);

        for(int i = 0; i < m; i++) {
            int first = edges[i][0];
            int second = edges[i][1];

            connected[first].push_back(second);
            connected[second].push_back(first);
        }

        if(isLoop(visited, connected, 0, -1)) {
            return false;
        }

        if(countEdges != n) return false;

        return true;
    }

    bool isLoop(vector<bool>& visited, vector<vector<int>>& connected, int curr, int parent) {
        visited[curr] = true;
        countEdges++;

        for(int i = 0; i < connected[curr].size(); i++) {
            if(connected[curr][i] == parent) continue;
            if(visited[connected[curr][i]]) return true;
            if(isLoop(visited, connected, connected[curr][i], curr)) return true;
        }
        return false;
    }
};
