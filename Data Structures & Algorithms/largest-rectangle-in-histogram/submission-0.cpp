class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxVal = 0;
        stack<int> st;
        int n = heights.size();
        for(int i = 0; i <= n; i++) {
            int currentHeight = 0;
            if(i != n) {
                currentHeight = heights[i];
            }

            while(!st.empty() && currentHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                int w = i;
                if(!st.empty()) {
                    w = i-st.top()-1;
                }

                maxVal = max(maxVal, w*h);
            }
            st.push(i);
        }

        return maxVal;
    }
};
