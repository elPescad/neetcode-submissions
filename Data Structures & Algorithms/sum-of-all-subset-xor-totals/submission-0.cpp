class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> res;
        int curr = 0;
        traverse(res, nums, 0, curr);

        int sum = 0;
        for(int i: res) {
            sum += i;
        }
        return sum;
    }

    void traverse(vector<int>& res, vector<int>& nums, int i, int& curr) {
        if(i == nums.size()) {
            res.push_back(curr);
            return;
        }

        curr ^= nums[i];
        traverse(res, nums, i+1, curr);
        curr ^= nums[i];
        traverse(res, nums, i+1, curr);
    }
};