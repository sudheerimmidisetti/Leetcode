class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
            mp[nums[i]].push_back(i);

        int minDist = INT_MAX;
        for (auto& [val, idx] : mp) {
            if (idx.size() < 3)
                continue;

            sort(idx.begin(), idx.end());

            for (int i = 0; i < idx.size() - 2; i++)
                minDist = min(minDist, abs(idx[i] - idx[i + 1]) +
                                           abs(idx[i + 1] - idx[i + 2]) +
                                           abs(idx[i + 2] - idx[i]));
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};