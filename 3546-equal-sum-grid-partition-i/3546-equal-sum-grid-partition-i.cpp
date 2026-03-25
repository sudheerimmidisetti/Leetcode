class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        long long total = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                total += grid[i][j];

        long long rowSum = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++)
                rowSum += grid[i][j];

            if (rowSum * 2 == total)
                return true;
        }

        vector<long long> colSums(n, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                colSums[j] += grid[i][j];

        long long colSum = 0;
        for (int j = 0; j < n - 1; j++) {
            colSum += colSums[j];
            if (colSum * 2 == total)
                return true;
        }

        return false;
    }
};