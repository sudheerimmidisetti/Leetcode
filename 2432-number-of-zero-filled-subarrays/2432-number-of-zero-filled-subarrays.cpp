class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt0 = 0, subArrayCnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                cnt0++;
            else {
                subArrayCnt += (cnt0 * (cnt0 + 1) / 2);
                cnt0 = 0;
            }
        }
        subArrayCnt += (cnt0 * (cnt0 + 1) / 2);

        return subArrayCnt;
    }
};