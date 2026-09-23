class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        vector<int> res;
        int n = nums.size();
        for(int i: nums) {
            count[i]++;
        }
        for(auto it: count) {
            if(it.second > n/3) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};