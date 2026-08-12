class Solution {
public:
    string minWindow(string s, string t) {
        array<int, 58> mp = {0};

        for(char c: t) {
            int val = c-'A';
            mp[val]++; 
        }

        int l = 0;
        int count = t.size();
        int minLength = INT_MAX;
        int start = l;
        for(int r = 0; r < s.size(); r++) {
            int val = s[r]-'A';
            if(mp[val] > 0) {
                count--;
            }
            mp[val]--;

            while(count == 0) {
                if(r-l+1 < minLength) {
                    minLength = r-l+1;
                    start = l;
                }

                val = s[l]-'A';
                mp[val]++;
                if(mp[val] > 0) {
                    count++;
                }
                l++;
            }
        }

        if(minLength == INT_MAX) {
            return "";
        }
        return s.substr(start, minLength);
    }
};
