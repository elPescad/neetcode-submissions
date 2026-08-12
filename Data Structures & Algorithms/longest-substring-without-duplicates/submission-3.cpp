class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;

        int length = 0;
        unordered_set<char> st;
        for(int r = 0; r < s.size(); r++) {
            while(st.contains(s[r])) {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            length = max(length, r-l+1);
        }

        return length;
    }
};
