class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int curr = 0;

        while(curr <= r) {
            if(nums[curr] == 0 && curr != l) {
                swap(nums[curr], nums[l]);
                l++;
            } else if(nums[curr] == 2 && curr != r) {
                swap(nums[curr], nums[r]);
                r--;
            } else {
                curr++;
            }
        }
    }
};