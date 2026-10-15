class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0) {
            int carry = (a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
/*
0000 0100 a
0000 0111 b

0000 1000 carry

0000 0100 a
0000 0111 b

0000 0011 a
0000 1000 b

0000 0000 carry

0000 1011 a
0000 0000 b

0000 1011 a
*/