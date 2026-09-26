class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        if(nums.size() < 4) {
            return res;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            for(int j = nums.size()-1; j >= i+2; j--) {
                if(j < nums.size()-1 && nums[j] == nums[j+1]) {
                    continue;
                }

                int l = i+1, r = j-1;
                while(l < r) {
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];

                    if(sum == target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;

                        while(nums[l] == nums[l-1] && l < j) {
                            l++;
                        }

                        while(nums[r] == nums[r+1] && r > i) {
                            r--;
                        }
                    } else if(sum > target) {
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }
        return res;
    }
};