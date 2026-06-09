class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxi = nums[0], mini = nums[0];

        for (int x : nums) {
            maxi = max(maxi, x * 1ll);
            mini = min(mini, x * 1ll);
        }

        return (maxi - mini) * k;
    }
};