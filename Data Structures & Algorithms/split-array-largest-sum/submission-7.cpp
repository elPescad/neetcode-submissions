class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        
        int l = *max_element(nums.begin(), nums.end());
        
        int r = accumulate(nums.begin(), nums.end(), 0);
        int maxi = r;


        while(l <= r) {
            int m = l + (r - l) / 2;

            int c = 1;
            int curr = 0;

            for (int i = 0; i < nums.size(); i++) {
                if (curr + nums[i] <= m) {
                    curr += nums[i];
                }
                else {
                    c++;
                    curr = nums[i];
                }
             
            }

            if (c <= k) {
                maxi = min(maxi, m);
                r = m - 1;
            }
            else l = m + 1;

        }

        return l;
    }
};