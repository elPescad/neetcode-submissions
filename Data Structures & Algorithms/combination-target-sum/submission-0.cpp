class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        traverse(res, curr, nums, target, 0);
        return res;
    }

    void traverse(vector<vector<int>>& res, vector<int>& curr, vector<int>& nums, int target, int i)
    {
        if(target == 0) {
            res.push_back(curr);
            return;
        }

        if(target < 0 || i == nums.size()) {
            return;
        }

        curr.push_back(nums[i]);
        traverse(res, curr, nums, target-nums[i], i);
        curr.pop_back();
        traverse(res, curr, nums, target, i+1);
    }
};
