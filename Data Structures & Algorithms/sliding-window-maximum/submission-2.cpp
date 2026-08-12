class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> res;

        int i = 0;
        while(i < k) {
            pq.push({nums[i], i});
            i++;
        }

        res.push_back(pq.top().first);
        if(pq.top().second == 0) {
            pq.pop();
        }

        int l = 1;
        for(int r = l + k-1; r < nums.size(); r++) {
            pq.push({nums[r], r});

            while(pq.top().second < l) {
                pq.pop();
            }
            res.push_back(pq.top().first);
            l++;
        }

        return res;
    }
};
