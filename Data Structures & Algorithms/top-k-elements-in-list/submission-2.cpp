class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>> largest;
        for(auto vec: mp) {
            largest.push({vec.second, vec.first});
        }

        for(int i = 0; i < k; i++) {
            if(!largest.empty()) {
                int num = largest.top().second;
                largest.pop();
                res.push_back(num);
            }
        }
        return res;
    }
};
