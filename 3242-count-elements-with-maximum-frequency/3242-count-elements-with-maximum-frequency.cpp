class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxFreq = INT_MIN;
        for (auto& val : nums) {
            mp[val]++;

            maxFreq = max(maxFreq, mp[val]);
        }

        int cnt = 0;
        for (auto& v : mp) {
            if (v.second == maxFreq)
                cnt++;
        }

        return cnt * maxFreq;
    }
};