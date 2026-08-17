class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if(n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int l = 0;
        int r = n;
        int sum = (n+m+1)/2;
        while(l <= r) {
            int mid1 = l+(r-l)/2;
            int mid2 = sum-mid1;

            int l1 = (mid1-1 >= 0) ? l1 = nums1[mid1-1] : INT_MIN;
            int r1 = (mid1 < n) ? r1 = nums1[mid1] : INT_MAX;
            int l2 = (mid2-1 >= 0) ? l2 = nums2[mid2-1] : INT_MIN;
            int r2 = (mid2 < m) ? r2 = nums2[mid2] : INT_MAX;

            if(l1 <= r2 && l2 <= r1) {
                if((m+n)%2 == 1) {
                    return max(l1, l2);
                }
                return (double)(max(l1,l2) + min(r1,r2))/2.0;
            } else if(l1 > r2) {
                r = mid1-1;
            } else {
                l = mid1+1;
            }
        }

        return -1;
    }
};