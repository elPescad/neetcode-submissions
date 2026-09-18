class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res = nums;

        int n = nums.size();
        int i = 0;
        while(i < n) {
            res.push_back(nums[i]);
            i++;
        }

        return res;
    }
};