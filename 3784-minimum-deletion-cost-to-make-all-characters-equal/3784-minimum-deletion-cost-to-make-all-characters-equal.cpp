class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n = s.size();

        unordered_map<int, long long> mp;
        long long totalCost = 0;
        for (int i = 0; i < n; i++) {
            totalCost += cost[i];
            mp[s[i]] += cost[i];
        }

        long long maxCost = 0;
        for (auto& x : mp)
            maxCost = max(maxCost, x.second);

        return totalCost - maxCost;
    }
};