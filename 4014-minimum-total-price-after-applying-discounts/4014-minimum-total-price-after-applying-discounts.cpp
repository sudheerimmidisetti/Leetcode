class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size();
        int m = discounts.size();

        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());

        double minCost = 0.0;

        int i = 0, j = 0;
        while (i < n) {
            if (j < m) {
                minCost += ((prices[i] * (100 - discounts[j])) / 100.0);
                j++;
            } else
                minCost += prices[i];

            i++;
        }

        return minCost;
    }
};