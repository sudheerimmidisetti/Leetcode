class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int cnt = 0;
        for (int i = 0; i <= m - 3; i++) {
            for (int j = 0; j <= n - 3; j++) {
                bool isMagicSquare = true;
                int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];

                unordered_set<int> st;
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        int num = grid[i + k][j + l];
                        if (num < 1 || num > 9 || st.count(num))
                            isMagicSquare = false;

                        st.insert(num);
                    }
                }

                for (int k = 0; k < 3; k++) {
                    if (grid[i][j + k] + grid[i + 1][j + k] + grid[i + 2][j + k] != sum)
                        isMagicSquare = false;

                    if (grid[i + k][j] + grid[i + k][j + 1] + grid[i + k][j + 2] != sum)
                        isMagicSquare = false;
                }

                if (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != sum)
                    isMagicSquare = false;

                if (grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] != sum)
                    isMagicSquare = false;

                if (isMagicSquare)
                    cnt++;
            }
        }

        return cnt;
    }
};