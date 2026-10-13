class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);

        for(int i = 0; i <= n; i++) {
            int curr = i;
            while(curr != 0) {
                res[i]++;
                curr = curr&(curr-1);
            }
        }
        return res;
    }
};
