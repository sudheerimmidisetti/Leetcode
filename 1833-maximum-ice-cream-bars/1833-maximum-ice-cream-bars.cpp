class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(costs.begin(), costs.end());

        map<int, int> mp;
        for (int c : costs)
            mp[c]++;

        int maxBars = 0;
        for (int c = 1; c <= maxCost && coins >= c; c++) {
            if (mp[c] == 0)
                continue;

            long long ttlCost = 1LL * c * mp[c];
            if (coins >= ttlCost) {
                maxBars += mp[c];
                coins -= ttlCost;
            } else {
                maxBars += coins / c;
                break;
            }
        }

        return maxBars;
    }
};