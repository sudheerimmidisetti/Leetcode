class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        vector<pair<int, int>> idxs[201];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                idxs[matrix[i][j]].push_back({i, j});
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int val = matrix[i][j];
                if (val == 0)
                    continue;

                bool can = true;
                for (int k = val + 1; k <= 200 && can; k++) {
                    for (int l = 0; l < idxs[k].size(); l++) {
                        int nxtR = idxs[k][l].first;
                        int nxtC = idxs[k][l].second;

                        int rDist = abs(nxtR - i);
                        int cDist = abs(nxtC - j);

                        if (rDist <= val && cDist <= val) {
                            if (rDist != val || cDist != val) {
                                can = false;
                                break;
                            }
                        }
                    }
                }

                if (can)
                    cnt++;
            }
        }

        return cnt;
    }
};