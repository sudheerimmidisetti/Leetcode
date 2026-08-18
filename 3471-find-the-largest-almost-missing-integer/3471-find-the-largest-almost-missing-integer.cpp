class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, bool> seen;
            for (int j = i; j < i + k; j++) {
                if (!seen[nums[j]]) {
                    mp[nums[j]]++;
                    seen[nums[j]] = true;
                }
            }
        }

        int res = -1;
        for (auto& num : mp) {
            if (num.second == 1)
                res = max(res, num.first);
        }

        return res;
    }
};