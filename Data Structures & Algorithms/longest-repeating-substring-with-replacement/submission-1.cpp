class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        unordered_map<char, int> mp;
        int longest = 1;
        int tempMax = 1;
        for(int r = 0; r < s.size(); r++) {
            mp[s[r]]++;
            tempMax = max(tempMax, mp[s[r]]);

            int difference = (r-l)-tempMax+1;
            if(difference-k <= 0) {
                longest = max(longest, r-l+1);
            } else {
                mp[s[l]]--;
                l++;
            }
        }

        return longest;
    }
};
