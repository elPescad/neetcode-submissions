class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> pref(height.size(), 0);
        vector<int> suff(height.size(), 0);
        pref[0] = height[0];
        for(int i = 1; i < height.size(); i++) {
            pref[i] = max(pref[i-1], height[i]);
        }

        suff[height.size()-1] = height[height.size()-1];
        for(int i = height.size()-2; i >= 0; i--) {
            suff[i] = max(suff[i+1], height[i]);
        }

        int countWater = 0;
        for(int i = 0; i < height.size(); i++) {
            if(min(suff[i], pref[i]) - height[i] > 0) {
                countWater += min(suff[i], pref[i]) - height[i];
            }
        }

        return countWater;
    }
};
