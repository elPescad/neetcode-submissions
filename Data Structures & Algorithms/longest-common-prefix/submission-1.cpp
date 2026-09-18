class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        int k = res.size();

        for(int i = 0; i < strs.size(); i++) {
            while(k > 0 && !strs[i].contains(res)) {
                k--;
                res = res.substr(0, k);
            }
        }

        return res;
    }
};