class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int incLen = 1, decLen = 1;
        int maxLen = 1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                incLen++;
                decLen = 1;
            } else if (nums[i] > nums[i + 1]) {
                decLen++;
                incLen = 1;
            } else {
                incLen = 1;
                decLen = 1;
            }

            maxLen = max(maxLen, max(incLen, decLen));
        }

        return maxLen;
    }
};