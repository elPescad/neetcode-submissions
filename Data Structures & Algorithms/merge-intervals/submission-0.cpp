class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        vector<int> inter = intervals[0];

        for(int i = 1; i < intervals.size(); i++) {
            if(inter[1] >= intervals[i][0]) {
                inter[1] = max(inter[1], intervals[i][1]);
            } else {
                res.push_back(inter);
                inter = intervals[i];
            }
        }
        res.push_back(inter);
        return res;
    }
};
