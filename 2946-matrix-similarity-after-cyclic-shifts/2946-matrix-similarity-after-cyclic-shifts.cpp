class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        k %= n;

        vector<vector<int>> tmp = mat;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                tmp[i][j] = mat[i][(j + k) % n];

        return mat == tmp;
    }
};