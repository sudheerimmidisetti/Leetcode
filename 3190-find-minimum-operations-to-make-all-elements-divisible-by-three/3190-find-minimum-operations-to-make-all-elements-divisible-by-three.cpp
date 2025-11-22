class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        int minOperations = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 3 == 2)
                minOperations += 1;
            else
                minOperations += nums[i] % 3;
        }

        return minOperations;
    }
};