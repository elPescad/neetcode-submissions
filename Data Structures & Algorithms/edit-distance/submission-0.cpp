class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 0; i <= n; i++) dp[m][i] = n-i;
        for(int j = 0; j <= m; j++) dp[j][n] = m-j;

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(word1[i] == word2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = 1+min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]});
                }
            }
        }
        return dp[0][0];
    }

    //monkeys
    //money

    // 0 0 0 0 7 0 
    // 0 0 0 0 6 0
    // 0 0 0 0 5 0
    // 0 0 0 0 4 0
    // 0 0 0 0 3 0
    // 0 0 0 0 2 0
    // 5 4 3 2 1 0
    // 0 0 0 0 0 0
};
