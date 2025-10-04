class Solution {
public:
    int maxArea(vector<int>& height) {
        int mostWater = INT_MIN;

        int i = 0, j = height.size() - 1;
        while (i < j) {
            mostWater = max(mostWater, (min(height[i], height[j]) * abs(i - j)));
            height[i] < height[j] ? i++ : j--;
        }

        return mostWater;
    }
};