class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        int partitions = 0;
        for (int i = 0; i < n - 1; i++) {
            int leftSum = accumulate(nums.begin(), nums.begin() + i, 0);
            int rightSum = accumulate(nums.begin() + i, nums.end(), 0);

            if (abs(leftSum - rightSum) % 2 == 0)
                partitions++;
        }

        return partitions;
    }
};