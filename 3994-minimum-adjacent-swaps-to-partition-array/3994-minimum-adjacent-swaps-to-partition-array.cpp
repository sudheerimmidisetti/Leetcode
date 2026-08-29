class Solution {
public:
    const int MOD = 1e9 + 7;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();

        int minSwapsCnt = 0, lCnt = 0, iCnt = 0, gCnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < a) {
                lCnt++;
                minSwapsCnt += (iCnt + gCnt);
            } else if (nums[i] <= b) {
                iCnt++;
                minSwapsCnt += gCnt;
            } else
                gCnt++;

            minSwapsCnt %= MOD;
        }

        return minSwapsCnt;
    }
};