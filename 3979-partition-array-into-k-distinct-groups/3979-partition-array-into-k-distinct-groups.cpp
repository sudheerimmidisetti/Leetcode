class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0)
            return false;

        unordered_map<int, int> mp;
        for (auto x : nums)
            mp[x]++;

        int noOfGroups = n / k;
        for (auto [num, cnt] : mp) {
            if (cnt > noOfGroups)
                return false;
        }

        return true;
    }
};