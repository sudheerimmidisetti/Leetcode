class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();

        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            set<int> stOdd, stEven;
            int len = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0)
                    stEven.insert(nums[j]);
                else
                    stOdd.insert(nums[j]);

                len++;
                if (stEven.size() == stOdd.size())
                    maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};