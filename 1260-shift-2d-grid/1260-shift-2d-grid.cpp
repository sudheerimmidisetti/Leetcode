class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        k %= (m * n);

        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int idx = (i * n) + j;
                int nIdx = (idx + k) % (m * n);

                int r = nIdx / n;
                int c = nIdx % n;

                res[r][c] = grid[i][j];
            }
        }

        return res;
    }
};