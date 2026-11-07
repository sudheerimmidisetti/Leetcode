class Solution {
public:
    int solve(vector<int> nums) {
        int m = nums.size();

        nums.push_back(0);
        // nums.push_back(0);
        for (int i = m - 3; i >= 0; i--)
            nums[i] += max(nums[i + 2], nums[i + 3]);

        return max(nums[0], nums[1]);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        return max(solve(vector<int>(nums.begin(), nums.end() - 1)),
                   solve(vector<int>(nums.begin() + 1, nums.end())));
    }
};