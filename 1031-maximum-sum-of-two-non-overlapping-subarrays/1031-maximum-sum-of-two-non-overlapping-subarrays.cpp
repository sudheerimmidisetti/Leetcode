class Solution {
public:
    int solve(vector<int>& nums, vector<int>& prefSum, int l, int m) {
        int n = nums.size();

        int maxSum = 0, currMax = 0;
        for (int i = l; i <= n - m; i++) {
            int curr1 = prefSum[i + m - 1] - (i > 0 ? prefSum[i - 1] : 0);
            int curr2 = prefSum[i - 1] - (i - l > 0 ? prefSum[i - l - 1] : 0);

            currMax = max(currMax, curr2);
            maxSum = max(maxSum, curr1 + currMax);
        }

        return maxSum;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();

        vector<int> prefSum(n, 0);

        prefSum[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefSum[i] = prefSum[i - 1] + nums[i];

        return max(solve(nums, prefSum, firstLen, secondLen),
                   solve(nums, prefSum, secondLen, firstLen));
    }
};