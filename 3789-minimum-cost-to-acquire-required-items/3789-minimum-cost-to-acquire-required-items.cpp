class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        if (need1 == 0 && need2 == 0)
            return 0;

        long long minReq = min(need1, need2);
        return minReq * min(cost1 + cost2, costBoth) +
               (need1 - minReq) * min(cost1, costBoth) +
               (need2 - minReq) * min(cost2, costBoth);
    }
};