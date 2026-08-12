class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = l;

        int length = 0;
        unordered_set<int> st;
        while(r < s.size()) {
            if(st.contains(s[r])) {
                st.erase(s[l]);
                l++;
            } else {
                st.insert(s[r]);
                r++;
                int getSt = st.size();
                length = max(length, getSt);
            }
        }

        return length;
    }
};
