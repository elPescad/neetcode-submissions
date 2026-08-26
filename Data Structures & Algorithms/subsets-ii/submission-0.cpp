class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> copy;
        sort(nums.begin(), nums.end());
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
        while(i + 1 < nums.size() && nums[i] == nums[i+1]) {
            i++; 
        }
        traverse(res, copy, nums, i+1);
    }
};
