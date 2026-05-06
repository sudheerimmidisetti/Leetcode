class Solution {
public:
    bool canSplit(vector<int>& nums, int maxSum, int k) {
        int sum = 0;
        int splits = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > maxSum) {
                splits++;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }
        return splits <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = 0, h = 0;

        for (int i = 0; i < nums.size(); i++) {
            l = max(l, nums[i]);
            h += nums[i];
        }

        int minimizedMaxSum = -1;
        while (l <= h) {
            int mid = (l + h) / 2;

            if (canSplit(nums, mid, k)) {
                minimizedMaxSum = mid;
                h = mid - 1;
            } else
                l = mid + 1;
        }

        return minimizedMaxSum;
    }
};