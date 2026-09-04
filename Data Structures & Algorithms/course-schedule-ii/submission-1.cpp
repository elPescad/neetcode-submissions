class Solution {
public:
    vector<int> res;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> pre(numCourses);
        vector<int> visited(numCourses, 0);

        for(int i = 0; i < prerequisites.size(); i++) {
            int first = prerequisites[i][1];
            int second = prerequisites[i][0];
            pre[second].push_back(first);
        }

        for(int i = 0; i < numCourses; i++) {
            if(visited[i] == 0) {
                if(isLoop(pre, visited, i)) {
                    return {};
                }
            }
        }
        return res;
    }

    bool isLoop(vector<vector<int>>& pre, vector<int>& visited, int curr) {
        if(visited[curr] == 1) {
            return true;
        }
        if(visited[curr] == 2) {
            return false;
        }

        visited[curr] = 1;

        for(int i = 0; i < pre[curr].size(); i++) {
            if(isLoop(pre, visited, pre[curr][i])) {
                return true;
            }
        }
        visited[curr] = 2;
        res.push_back(curr);
        return false;
    }
};
