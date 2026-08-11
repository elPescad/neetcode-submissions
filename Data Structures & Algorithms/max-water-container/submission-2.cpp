class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int maxA = 0;
        while(left < right) {
            maxA = max(maxA, min(heights[left],heights[right]) * (right-left));
            if(heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxA;
    }
};
