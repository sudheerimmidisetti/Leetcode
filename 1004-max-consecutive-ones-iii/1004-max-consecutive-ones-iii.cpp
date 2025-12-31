class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int start = 0, zerosCnt = 0, maxOnes = 0;
        for (int end = 0; end < n; end++) {
            if (nums[end] == 0)
                zerosCnt++;

            while (zerosCnt > k) {
                if (nums[start] == 0)
                    zerosCnt--;

                start++;
            }

            maxOnes = max(maxOnes, end - start + 1);
        }

        return maxOnes;
    }
};