class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& vist, vector<vector<char>>& grid, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || vist[i][j] || grid[i][j] != '1')
            return;

        vist[i][j] = true;
        
        dfs(i - 1, j, vist, grid, n, m);
        dfs(i, j + 1, vist, grid, n, m);
        dfs(i + 1, j, vist, grid, n, m);
        dfs(i, j - 1, vist, grid, n, m);
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> vist(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vist[i][j]) {
                    islands++;

                    dfs(i, j, vist, grid, n, m);
                }
            }
        }

        return islands;
    }
};