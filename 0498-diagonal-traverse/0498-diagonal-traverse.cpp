class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> res;
        
        int i = 0, j = 0;
        bool up = true;
        while (res.size() < m * n) {
            res.push_back(mat[i][j]);

            if (up) {
                if (j == n - 1) {
                    i++;
                    up = false;
                } else if (i == 0) {
                    j++;
                    up = false;
                } else {
                    i--;
                    j++;
                }
            } else {
                if (i == m - 1) {
                    j++;
                    up = true;
                } else if (j == 0) {
                    i++;
                    up = true;
                } else {
                    i++;
                    j--;
                }
            }
        }

        return res;
    }
};