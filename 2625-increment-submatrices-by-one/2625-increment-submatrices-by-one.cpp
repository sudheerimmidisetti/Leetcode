class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> prefSum(n, vector<int>(n + 1, 0));
        for (auto& q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];

            for (int i = r1; i <= r2; i++) {
                prefSum[i][c1]++;

                if (c2 + 1 < n)
                    prefSum[i][c2 + 1]--;
            }
        }

        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0)
                    res[i][j] = prefSum[i][j];
                else
                    res[i][j] = res[i][j - 1] + prefSum[i][j];
            }
        }

        return res;
    }
};