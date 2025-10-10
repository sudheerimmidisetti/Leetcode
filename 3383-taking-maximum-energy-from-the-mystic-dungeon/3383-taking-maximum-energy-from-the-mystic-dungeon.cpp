class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();

        vector<int> dp(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (i + k >= n)
                dp[i] = energy[i];
            else
                dp[i] += (dp[i + k] + energy[i]);
        }

        int maxEnergy = INT_MIN;
        for (int i = 0; i < n; i++)
            maxEnergy = max(maxEnergy, dp[i]);

        return maxEnergy;
    }
};