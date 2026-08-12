class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = l+1;
        int difference = 0;

        while(r < prices.size()) {
            if(prices[l] > prices[r]) {
                l = r;
                r = l+1;
            } else {
                difference = max(difference, prices[r] - prices[l]);
                r++;
            }
        }

        return difference;
    }
};
