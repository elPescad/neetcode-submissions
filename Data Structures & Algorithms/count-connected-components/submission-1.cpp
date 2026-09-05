class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>> connected(n);
        vector<bool> visited(n, false);

        for(int i = 0; i < m; i++) {
            int first = edges[i][0];
            int second = edges[i][1];

            connected[first].push_back(second);
            connected[second].push_back(first);
        }

        int count = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                isLoop(i, connected, visited);
                count++;
            }
        }

        return count;
    }
    
    void isLoop(int curr, vector<vector<int>>& connected, vector<bool>& visited) {
        visited[curr] = true;

        for(int neighbor: connected[curr]) {
            if(!visited[neighbor]) isLoop(neighbor, connected, visited);
        }
    }
};
