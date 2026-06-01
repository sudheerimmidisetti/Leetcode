class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();

        if (n == 1)
            return cost[0];

        sort(cost.rbegin(), cost.rend());

        int minCost = 0;
        for (int i = 1; i < n; i += 3)
            minCost += (cost[i] + cost[i - 1]);

        if (n % 3 == 1)
            minCost += cost[n - 1];

        return minCost;
    }
};