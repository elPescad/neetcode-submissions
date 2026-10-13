class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;

        for(int i = 0; i <= n; i++) {
            int curr = i;
            int count = 0;
            while(curr != 0) {
                curr = curr&(curr-1);
                count++;
            }
            res.push_back(count);
        }
        return res;
    }
};
