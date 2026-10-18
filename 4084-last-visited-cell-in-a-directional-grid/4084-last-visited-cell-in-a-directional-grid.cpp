class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> vist(n, vector<bool>(m, false));

        int r = 0, c = 0;
        vist[r][c] = true;
        while (true) {
            int newR = r, newC = c;
            if (grid[r][c] == 'L')
                newC--;
            else if (grid[r][c] == 'R')
                newC++;
            else if (grid[r][c] == 'U')
                newR--;
            else
                newR++;

            if (newR < 0 || newR >= n || newC < 0 || newC >= m)
                break;
            
            if (vist[newR][newC])
                break;

            r = newR;
            c = newC;

            vist[r][c] = true;
        }

        return {r, c};
    }
};