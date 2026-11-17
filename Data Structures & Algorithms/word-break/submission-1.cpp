class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1, false);

        dp[n] = true;

        for(int i = n-1; i >= 0; i--) {
            for(string& m : wordDict) {
                int calc = m.size();
                if(calc+i <= n && s.substr(i, calc) == m) {
                    dp[i] = dp[i+calc];
                }
                if(dp[i]) break;
            }
        }

        return dp[0];
    }
};