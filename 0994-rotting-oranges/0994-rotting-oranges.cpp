class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        if (fresh == 0)
            return 0;

        vector<int> dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};

        int minutes = 0;
        while (!q.empty()) {
            int sz = q.size();

            bool rotted = false;
            for (int i = 0; i < sz; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int r2 = r + dr[d];
                    int c2 = c + dc[d];

                    if (r2 < 0 || r2 >= m || c2 < 0 || c2 >= n)
                        continue;

                    if (grid[r2][c2] == 1) {
                        grid[r2][c2] = 2;
                        q.push({r2, c2});

                        fresh--;
                        rotted = true;
                    }
                }
            }

            if (rotted)
                minutes++;
        }

        return (fresh == 0) ? minutes : -1;
    }
};