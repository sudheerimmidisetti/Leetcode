class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int cnt1 = 0;
        for (auto& val : nums) {
            if (val == 1)
                cnt1++;
        }

        if (cnt1 > 0)
            return n - cnt1;

        int minCnt = INT_MAX;
        for (int i = 0; i < n; i++) {
            int gcdVal = nums[i];
            for (int j = i + 1; j < n; j++) {
                gcdVal = __gcd(gcdVal, nums[j]);

                if (gcdVal == 1) {
                    minCnt = min(minCnt, j - i + 1);
                    break;
                }
            }
        }

        return minCnt == INT_MAX ? -1 : minCnt + n - 2;
    }
};