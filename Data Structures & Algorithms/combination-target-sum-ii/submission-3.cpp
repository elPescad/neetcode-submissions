class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        res.clear();
        vector<int> curr;
        traverse(res, curr, candidates, target, 0);
        return res;
    }
    
    void traverse(vector<vector<int>>& res, vector<int>& curr, vector<int>& candidates, int target, int i) {
        if(target == 0) {
            res.push_back(curr);
            return;
        }
        if(target < 0 || i == candidates.size()) {
            return;
        }

        curr.push_back(candidates[i]);
        traverse(res, curr, candidates, target-candidates[i], i+1);
        curr.pop_back();
        while(i+1 < candidates.size() && candidates[i] == candidates[i+1]) {
            i++;
        }
        traverse(res, curr, candidates, target, i+1);
    }
};
