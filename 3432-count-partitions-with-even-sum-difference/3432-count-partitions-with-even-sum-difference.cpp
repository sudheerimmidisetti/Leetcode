class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int leftSum = 0, rightSum = accumulate(nums.begin(), nums.end(), 0);

        int partitions = 0;
        for (int i = 0; i < n - 1; i++) {
            leftSum += nums[i];
            rightSum -= nums[i];

            if (abs(leftSum - rightSum) % 2 == 0)
                partitions++;
        }

        return partitions;
    }
};