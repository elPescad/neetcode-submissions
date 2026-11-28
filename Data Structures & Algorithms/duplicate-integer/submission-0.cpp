class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        for(int i : nums) {
            if(st.contains(i)) return true;
            st.insert(i);
        }
        return false;
    }
};