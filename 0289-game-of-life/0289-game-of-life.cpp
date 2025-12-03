class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();

        vector<vector<int>> tmp = board;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = 0;
                
                if (i > 0 && j > 0 && tmp[i - 1][j - 1] == 1)
                    cnt++;
                if (i > 0 && tmp[i - 1][j] == 1)
                    cnt++;
                if (i > 0 && j + 1 < n && tmp[i - 1][j + 1] == 1)
                    cnt++;
                if (j > 0 && tmp[i][j - 1] == 1)
                    cnt++;
                if (j + 1 < n && tmp[i][j + 1] == 1)
                    cnt++;
                if (i + 1 < m && j > 0 && tmp[i + 1][j - 1] == 1)
                    cnt++;
                if (i + 1 < m && tmp[i + 1][j] == 1)
                    cnt++;
                if (i + 1 < m && j + 1 < n && tmp[i + 1][j + 1] == 1)
                    cnt++;

                if (tmp[i][j] == 1 && cnt < 2)
                    board[i][j] = 0;
                if (tmp[i][j] == 1 && (cnt == 2 || cnt == 3))
                    board[i][j] = 1;
                if (tmp[i][j] == 1 && cnt > 3)
                    board[i][j] = 0;
                if (tmp[i][j] == 0 && cnt == 3)
                    board[i][j] = 1;
            }
        }
    }
};