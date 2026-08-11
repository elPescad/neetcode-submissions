class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp = cost;

        dp.push_back(0);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < dp.size(); i++) {
            dp[i] = min(dp[i] + dp[i-1], dp[i] + dp[i-2]);
        }

        return dp[cost.size()];
    }
};
