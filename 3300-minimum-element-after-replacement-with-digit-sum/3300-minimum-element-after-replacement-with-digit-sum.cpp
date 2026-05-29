class Solution {
public:
    int minElement(vector<int>& nums) {
        int minEle = INT_MAX;
        for (int i : nums) {
            int digitSum = 0;
            while (i > 0) {
                digitSum += i % 10;
                i /= 10;
            }

            minEle = min(minEle, digitSum);
        }

        return minEle;
    }
};