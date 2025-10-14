class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i <= n - 2 * k; i++) {
            bool subArray1 = true;
            
            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] >= nums[j + 1]) {
                    subArray1 = false;
                    break;
                }
            }

            bool subArray2 = true;
            for (int j = i + k; j < i + 2 * k - 1; j++) {
                if (nums[j] >= nums[j + 1]) {
                    subArray2 = false;
                    break;
                }
            }

            if (subArray1 && subArray2)
                return true;
        }

        return false;
    }
};