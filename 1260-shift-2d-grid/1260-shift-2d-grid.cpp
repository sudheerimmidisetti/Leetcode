class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        
        while (k--) {
            vector<vector<int>> tmp(m, vector<int>(n));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (j == n - 1) {
                        if (i == m - 1)
                            tmp[0][0] = grid[i][j];
                        else
                            tmp[i + 1][0] = grid[i][j];
                    } else
                        tmp[i][j + 1] = grid[i][j];
                }
            }

            grid = tmp;
        }

        return grid;
    }
};