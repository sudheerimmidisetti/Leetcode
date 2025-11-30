class Solution {
public:
    long long reverseNum(long long val) {
        long long rev = 0;
        while (val > 0) {
            rev = rev * 10 + (val % 10);
            val /= 10;
        }

        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<long long, int> mp;

        int minDiff = INT_MAX;
        for (int i = 0; i < n; i++) {
            auto idx = mp.find(nums[i]);
            if (idx != mp.end())
                minDiff = min(minDiff, abs(i - idx->second));

            long long val = reverseNum(nums[i]);
            mp[val] = i;
        }

        return (minDiff == INT_MAX) ? -1 : minDiff;
    }
};