class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int ttlSum = accumulate(nums.begin(), nums.end(), 0);
        int reqSum = ttlSum - x;

        if (reqSum < 0)
            return -1;

        int i = 0, sum = 0, maxLenSubarray = -1;
        for (int j = 0; j < n; j++) {
            sum += nums[j];

            while (sum > reqSum && i <= j) {
                sum -= nums[i];
                i++;
            }

            if (sum == reqSum)
                maxLenSubarray = max(maxLenSubarray, j - i + 1);
        }

        return maxLenSubarray == -1 ? -1 : n - maxLenSubarray;
    }
};