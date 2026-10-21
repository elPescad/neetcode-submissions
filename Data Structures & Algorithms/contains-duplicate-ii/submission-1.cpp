class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;

        int l = 0;
        for(int r = 0; r < nums.size(); r++) {
            if(r-l > k) st.erase(nums[l++]);
            if(st.contains(nums[r])) return true;
            st.insert(nums[r]);
        }
        return false;
    }
};