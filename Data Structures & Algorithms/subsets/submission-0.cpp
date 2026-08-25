class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> copy;
        res.push_back(copy);
        int i = 0;
        traverse(res, copy, nums, i);
        return res;
    }

    void traverse(vector<vector<int>>& res, vector<int>& copy, vector<int>& nums, int i) {
        if(i == nums.size()) {
            return;
        }

        for(int index = i; index < nums.size(); index++) {
            copy.push_back(nums[index]);
            traverse(res, copy, nums, index+1);
            res.push_back(copy);
            copy.pop_back();
        }
    }
};
