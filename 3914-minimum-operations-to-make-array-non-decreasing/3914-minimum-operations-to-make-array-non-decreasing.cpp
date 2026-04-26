class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n = nums.size();

        long long minSum = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                minSum += (nums[i - 1] - nums[i]);
                // nums[i] = nums[i - 1];
            }
        }

        return minSum;
    }
};