class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> arraySum;
        for (int i = 0; i < n - 1; i++) {
            arraySum.clear();

            for (int j = 1; j < nums.size(); j++)
                arraySum.push_back((nums[j - 1] + nums[j]) % 10);

            nums.clear();
            nums = arraySum;
        }

        return nums[0];
    }
};