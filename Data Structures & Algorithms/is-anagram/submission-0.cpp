class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> mp;

        for(char c: s) {
            mp[c]++;
        }

        for(char c: t) {
            mp[c]--;
            if(mp[c] == 0) mp.erase(c);
        }

        return mp.size() == 0;
    }
};
