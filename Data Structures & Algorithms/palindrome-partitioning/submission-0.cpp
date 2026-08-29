class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> part;
        traverse(0, 0, s, part);
        return res;
    }

    void traverse(int j, int i, string& s, vector<string>& part) {
        if(i == s.size()) {
            if(i == j) {
                res.push_back(part);
            }
            return;
        }

        if(isPalindrome(s, j, i)) {
            part.push_back(s.substr(j, i-j+1));
            traverse(i+1, i+1, s, part);
            part.pop_back();
        }

        traverse(j, i+1, s, part);
    }

    bool isPalindrome(const string& wrd, int l, int r) {
        while(l <= r) {
            if(wrd[l] != wrd[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
