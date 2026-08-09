class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> sum;

        for(int i = 0; i < nums.size(); i++) {
            if(sum.contains(target - nums[i])) {
                res.push_back(sum[target-nums[i]]);
                res.push_back(i);
            }
            sum[nums[i]] = i;
        }

        return res;
    }
};
