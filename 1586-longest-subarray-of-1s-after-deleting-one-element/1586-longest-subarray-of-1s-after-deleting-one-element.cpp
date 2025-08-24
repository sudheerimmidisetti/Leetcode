class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int longestSubarray = 0;
        int before0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                cnt1++;
            else {
                longestSubarray = max(longestSubarray, before0 + cnt1);

                before0 = cnt1;
                cnt1 = 0;
            }
        }
        longestSubarray = max(longestSubarray, before0 + cnt1);

        if (longestSubarray == n)
            return n - 1;

        return longestSubarray;
    }
};