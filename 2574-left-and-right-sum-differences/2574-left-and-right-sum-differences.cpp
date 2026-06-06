class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for (int num : nums)
            totalSum += num;

        vector<int> res;

        int leftSum = 0;
        for (int i = 0; i < n; i++) {
            int rightSum = totalSum - leftSum - nums[i];
            res.push_back(abs(leftSum - rightSum));
            leftSum += nums[i];
        }

        return res;
    }
};