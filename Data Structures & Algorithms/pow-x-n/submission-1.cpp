class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(x == 0) return 0;

        double res = 1;
        int power = abs(n);

        while(power) {
            if(power & 1) {
                res *= x;
            }
            x *= x;
            power >>= 1;
        }

        return n > 0 ? res : 1 / res;
    }
};
