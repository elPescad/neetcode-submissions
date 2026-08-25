class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> copy;
        traverse(res, copy, nums, 0);
        return res;
    }

    void traverse(vector<vector<int>>& res, vector<int>& copy, vector<int>& nums, int i) {
        if(i == nums.size()) {
            res.push_back(copy);
            return;
        }

        copy.push_back(nums[i]);
        traverse(res, copy, nums, i+1);
        copy.pop_back();
        traverse(res, copy, nums, i+1);
    }
};
