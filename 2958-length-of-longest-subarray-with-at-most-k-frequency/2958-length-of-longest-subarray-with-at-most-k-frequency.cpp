class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        
        int maxLen = 0, i = -1;
        for (int j = 0; j < n; j++) {
            mp[nums[j]]++;
            while (mp[nums[j]] > k) {
                i++;
                mp[nums[i]]--;
            }
            maxLen = max(maxLen, j - i);
        }

        return maxLen;
    }
};