class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<long long> prefSum(n, 0);

        prefSum[0] = stones[0];
        for (int i = 1; i < n; i++)
            prefSum[i] = prefSum[i - 1] + stones[i];

        long long maxi = prefSum[n - 1];
        for (int i = n - 2; i >= 1; i--)
            maxi = max(maxi, prefSum[i] - maxi);

        return maxi;
    }
};