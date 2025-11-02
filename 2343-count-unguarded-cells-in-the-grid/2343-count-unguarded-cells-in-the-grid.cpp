class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (auto g : guards)
            grid[g[0]][g[1]] = 16;

        for (auto w : walls)
            grid[w[0]][w[1]] = 45;

        for (auto g : guards) {
            int row = g[0], col = g[1];

            for (int r = row - 1; r >= 0; r--) {
                if (grid[r][col] == 45 || grid[r][col] == 16)
                    break;

                grid[r][col] = 264;
            }

            for (int r = row + 1; r < grid.size(); r++) {
                if (grid[r][col] == 45 || grid[r][col] == 16)
                    break;

                grid[r][col] = 264;
            }

            for (int c = col - 1; c >= 0; c--) {
                if (grid[row][c] == 45 || grid[row][c] == 16)
                    break;

                grid[row][c] = 264;
            }

            for (int c = col + 1; c < grid[row].size(); c++) {
                if (grid[row][c] == 45 || grid[row][c] == 16)
                    break;

                grid[row][c] = 264;
            }
        }

        int cnt = 0;
        for (auto row : grid) {
            for (auto cell : row) {
                if (cell == 0)
                    cnt++;
            }
        }

        return cnt;
    }
};