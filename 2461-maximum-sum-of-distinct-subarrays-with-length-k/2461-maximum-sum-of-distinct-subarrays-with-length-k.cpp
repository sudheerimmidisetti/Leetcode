class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        long long maxSum = 0, sum = 0;
        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;
            sum += nums[i];
        }

        if (mp.size() == k)
            maxSum = sum;

        for (int i = k; i < n; i++) {
            sum += nums[i];
            sum -= nums[i - k];
            mp[nums[i]]++;

            if (mp[nums[i - k]] == 1)
                mp.erase(nums[i - k]);
            else
                mp[nums[i - k]]--;

            if (mp.size() == k)
                maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};