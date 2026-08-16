class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l <= r) {
            int mid = l+(r-l)/2;
            if(nums[mid] >= nums[l]) {
                int res = binary(l, mid, nums, target);
                if(res != -1 && nums[res] == target) {
                    return res;
                }
                l = mid+1;
            } else {
                int res = binary(mid, r, nums, target);
                if(res != -1 && nums[res] == target) {
                    return res;
                }
                r = mid-1;
            }
        }

        return -1;
    }

    int binary(int l, int r, vector<int>& nums, const int& target) {
        while(l <= r) {
            int mid = l+(r-l)/2;
            if(nums[mid] < target) {
                l = mid + 1;
            } else if(nums[mid] > target) {
                r = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
