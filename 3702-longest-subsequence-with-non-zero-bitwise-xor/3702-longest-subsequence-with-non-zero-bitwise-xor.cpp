class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        bool zeros = true;
        int xorVal = 0;
        for (int num : nums) {
            xorVal ^= num;

            if (num != 0)
                zeros = false;
        }

        if (zeros)
            return 0;

        return xorVal != 0 ? n : n - 1;
    }
};