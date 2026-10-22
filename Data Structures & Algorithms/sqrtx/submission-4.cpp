class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        int res = 0;
        while(l <= r) {
            int m = l +(r-l)/2;
            long long temp = (long long) m * m;
            if(temp > x) {
                r = m - 1;
            } else if(temp < x) {
                l = m + 1;
                res = m;
            } else {
                return m;
            }
        }

        return res;
    }
};