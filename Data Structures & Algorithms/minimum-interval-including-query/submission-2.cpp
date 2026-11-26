class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size(), p = queries.size();

        vector<pair<int, int>> sortedQueries(p);
        for(int i = 0; i < p; i++) {
            sortedQueries[i] = {queries[i], i};
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        sort(intervals.begin(), intervals.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> res(p, -1);
        int i = 0;
        for(auto& [que, idx] : sortedQueries) {
            while(i < n && intervals[i][0] <= que) {
                int left = intervals[i][0];
                int right = intervals[i][1];
                pq.push({right-left+1, right});
                i++;
            }

            while(!pq.empty() && pq.top().second < que) {
                pq.pop();
            }

            if(!pq.empty()) {
                res[idx] = pq.top().first;
            }
        }

        return res;
    }
};
