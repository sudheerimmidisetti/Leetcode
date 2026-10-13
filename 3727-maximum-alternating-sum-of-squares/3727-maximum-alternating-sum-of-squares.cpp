class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0)
                nums[i] *= -1;
        }
        
        sort(nums.begin(), nums.end());

        long long maxSum = 0;
        for (int i = 0; i < (n / 2); i++)
            maxSum -= (nums[i] * nums[i]);
        
        for (int i = (n / 2); i < n; i++)
            maxSum += (nums[i] * nums[i]);

        return maxSum;
    }
};