class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int currNum = nums[0];

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == currNum) {
                count++;
            } else if(count == 0) {
                currNum = nums[i];
                count++;
            } else {
                count--;
            }
        }

        return currNum;
    }
};