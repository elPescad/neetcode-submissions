class Solution {
public:
    vector<string> nums = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) {
            return {};
        }
        vector<string> res;
        string curr = "";
        traverse(res, curr, digits, 0);
        return res;
    }

    void traverse(vector<string>& res, string& curr, string& digits, int i) {
        if(i == digits.size()) {
            res.push_back(curr);
            return;
        }

        int c = digits[i] - '2';
        string currNum = nums[c];
        for(int j = 0; j < currNum.length(); j++) {
            curr += currNum[j];
            traverse(res, curr, digits, i+1);
            curr.pop_back();
        }
    }
};
