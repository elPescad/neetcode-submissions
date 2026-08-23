class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> alpha(26, 0);

        for(char c: tasks) {
            alpha[c - 'A']++;
        }

        priority_queue<int> pq;
        for(int i: alpha) {
            if(i > 0) {
                pq.push(i);
            }
        }

        queue<pair<int, int>> q;
        int time = 0;
        while(!pq.empty() || !q.empty()) {
            time++;

            if(pq.empty()) {
                time = q.front().second;
            } else {
                int cnt = pq.top() - 1;
                pq.pop();
                if(cnt > 0) {
                    q.push({cnt, time+n});
                }
            }

            if(!q.empty() && time == q.front().second) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
