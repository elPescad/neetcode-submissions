class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int> res(n*2);

        for(int i = 0; i < n; i++) {
            res[i] = nums[i];
            res[i+n] = nums[i];
        }

        return res;
    }
};