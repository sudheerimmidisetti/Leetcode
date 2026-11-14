class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        int minSum = INT_MAX;
        for (int length = l; length <= r; length++) {
            for (int i = 0; i <= n - length; i++) {
                int sum = prefix[i + length] - prefix[i];
                if (sum > 0)
                    minSum = min(minSum, sum);
            }
        }

        return minSum == INT_MAX ? -1 : minSum;
    }
};