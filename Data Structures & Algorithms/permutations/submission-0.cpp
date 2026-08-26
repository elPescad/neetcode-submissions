class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        traverse(res, nums, 0);
        return res;
    }

    void traverse(vector<vector<int>>& res, vector<int>& nums, int start){
        if(start == nums.size()) {
            res.push_back(nums);
            return;
        }

        for(int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            traverse(res, nums, start+1);
            swap(nums[i], nums[start]);
        }
    }
};
