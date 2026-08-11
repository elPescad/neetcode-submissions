class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        if(nums.size() == 0) {
            return 0;
        }
        vector<int> rob1(nums.begin()+1, nums.end());
        vector<int> rob2(nums.begin(), nums.end()-1);

        if(rob1.size() == 2) {
            int maxRob1 = max(rob1[0], rob1[1]);
            int maxRob2 = max(rob2[0], rob2[1]);
            return max(maxRob1, maxRob2);
        } else if(rob1.size() == 1) {
            return max(rob1[0], rob2[0]);
        }

        rob1[1] = max(rob1[0], rob1[1]);
        rob2[1] = max(rob2[0], rob2[2]);

        for(int i = 2; i < rob1.size(); i++) {
            int take = rob1[i-2] + rob1[i];
            int skip = rob1[i-1];
            rob1[i] = max(take, skip);

            take = rob2[i-2] + rob2[i];
            skip = rob2[i-1];
            rob2[i] = max(take, skip);
        }

        return max(rob1[rob1.size()-1], rob2[rob2.size()-1]);
    }
};
