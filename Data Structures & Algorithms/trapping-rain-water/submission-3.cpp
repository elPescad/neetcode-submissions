class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;

        int leftMax = height[l];
        int rightMax = height[r];

        int longest = 0;
        while(l < r) {
            if(leftMax < rightMax) {
                l++;
                if(height[l] < leftMax) {
                    longest += leftMax - height[l];
                } else {
                    leftMax = height[l];
                }
            } else {
                r--;
                if(height[r] < rightMax) {
                    longest += rightMax - height[r];
                } else {
                    rightMax = height[r];
                }
            }
        }

        return longest;
    }
};
