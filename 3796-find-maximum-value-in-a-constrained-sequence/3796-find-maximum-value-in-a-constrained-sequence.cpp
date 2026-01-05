class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions,
                   vector<int>& diff) {
        vector<int> res(n, INT_MAX);

        res[0] = 0;
        for (auto& x : restrictions)
            res[x[0]] = min(res[x[0]], x[1]);

        for (int i = 1; i < n; i++)
            res[i] = min(res[i], res[i - 1] + diff[i - 1]);

        for (int i = n - 2; i >= 0; i--)
            res[i] = min(res[i], res[i + 1] + diff[i]);

        int maxVal = INT_MIN;
        for (auto& x : res)
            maxVal = max(maxVal, x);

        return maxVal;
    }
};