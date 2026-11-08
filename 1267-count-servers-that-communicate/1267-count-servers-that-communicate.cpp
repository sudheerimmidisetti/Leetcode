class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<int> rowsCnt(n, 0), colsCnt(m, 0);
        
        int serversCnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    serversCnt++;
                    rowsCnt[i]++;
                    colsCnt[j]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && rowsCnt[i] == 1 && colsCnt[j] == 1)
                    serversCnt--;
            }
        }

        return serversCnt;
    }
};