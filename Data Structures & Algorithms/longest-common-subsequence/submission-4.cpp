class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        if(n > m) {
            return longestCommonSubsequence(text2, text1);
        }
        
        unordered_map<char, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[text1[i]].push_back(i);
        }

        vector<int> seq;
        for(char c : text2) {
            if(mp.contains(c)) {
                for(int k = mp[c].size()-1; k >= 0; k--) {
                    seq.push_back(mp[c][k]);
                }
            }
        }

        int len = seq.size();
        vector<int> dp(len, 1);
        int maxVal = 0;

        for(int i = len-1; i >= 0; i--) {
            for(int j = i+1; j < len; j++) {
                if(seq[i] < seq[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            maxVal = max(maxVal, dp[i]);
        }

        return maxVal;
    }
};
