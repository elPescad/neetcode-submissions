class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        unordered_set<int> seen;
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            count[nums[i]]++;
            if(!seen.contains(nums[i]) && count[nums[i]] > n/3) {
                seen.insert(nums[i]);
                res.push_back(nums[i]);
            }
        }

        return res;
    }
};