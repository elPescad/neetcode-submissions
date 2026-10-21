class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minVal = INT_MAX;
        int l = 0;

        int sum = 0;
        for(int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            while(sum >= target) {
                minVal = min(minVal, r-l+1);
                sum -= nums[l++];
            }
        }

        return minVal == INT_MAX ? 0 : minVal;
    }
};