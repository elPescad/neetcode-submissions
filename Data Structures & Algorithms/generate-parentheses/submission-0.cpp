class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string str = "";
        vector<string> res;
        traverse(res, str, 0, 0, n);
        return res;
    }

    void traverse(vector<string>& res, string& str, int l, int r, const int& n) {
        if(l == r && l == n) {
            res.push_back(str);
            return;
        } 

        if(l < n) {
            str += '(';
            traverse(res, str, l+1, r, n);
            str.pop_back();
        }
        if(r < l) {
            str += ')';
            traverse(res, str, l, r+1, n);

            str.pop_back();
        }
    }
};
