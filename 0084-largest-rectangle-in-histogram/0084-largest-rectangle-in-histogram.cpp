class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int> st;

        vector<int> prev(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (!st.empty())
                prev[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        vector<int> next(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (!st.empty())
                next[i] = st.top();

            st.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = next[i] - prev[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }

        return maxArea;
    }
};