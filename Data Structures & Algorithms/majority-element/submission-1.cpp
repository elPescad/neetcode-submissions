class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int currNum = nums[0];

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == currNum) {
                count++;
            } else {
                count--;
            }

            if(count < 0) {
                count = 1;
                currNum = nums[i];
            }
        }

        return currNum;
    }
};