class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        int k = nums.size();
        int i = 0;

        while(i < k) {
            if(nums[i] == val) {
                swap(nums[i], nums[k-1]);
                nums.pop_back();
                k--;
                continue;
            }

            if(nums[i] != val) count++;
            i++;
        }
        return count;
    }
};