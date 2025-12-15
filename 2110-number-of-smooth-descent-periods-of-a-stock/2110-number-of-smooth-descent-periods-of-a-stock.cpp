class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();

        long long totalCnt = 1, currCnt = 1;
        for (int i = 1; i < n; i++) {
            if (prices[i] == prices[i - 1] - 1)
                currCnt++;
            else
                currCnt = 1;

            totalCnt += currCnt;
        }

        return totalCnt;
    }
};