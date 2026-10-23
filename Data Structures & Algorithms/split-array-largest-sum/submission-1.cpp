class Solution {
private:
    int n;
    vector<int> sum;
public:
    int splitArray(vector<int>& nums, int k) {
        n = nums.size();
        sum.resize(n+1, 0);
        for(int i = 1; i <= n; i++) {
            sum[i] = nums[i-1] + sum[i-1];
        }

        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int res = r;
        

        while(l <= r) {
            int m = l+(r-l)/2;

            if(canSplit(m, k)) {
                res = m;
                r = m-1;
            } else {
                l = m+1;
            }
        }

        return res;
    }

    bool canSplit(int largest, int k) {
        int subarrays = 0, i = 0;
        while(i < n) {
            int l = i + 1, r = n;
            while(l <= r) {
                int m = l + (r-l)/2;
                if(sum[m] - sum[i] <= largest) {
                    l = m+1;
                } else{
                    r = m-1;
                }
            }
            subarrays++;
            i = r;
            if(subarrays > k) {
                return false;
            }
        }
        return true;
    }
};