class Solution {
public:
    bool can(int i, int j, string &s, string &p, int n, int m, vector<vector<bool>>& dp) {
        if (i == n && j == m)
            return true;

        if (j == m)
            return false;

        if (dp[i][j] != false)
            return dp[i][j];

        if (j + 1 < m && p[j + 1] == '*') {
            bool skip = can(i, j + 2, s, p, n, m, dp);
            bool take = false;

            if (i < n && (s[i] == p[j] || p[j] == '.'))
                take = can(i + 1, j, s, p, n, m, dp);

            dp[i][j] = skip || take;
        } else {
            if (i < n && (s[i] == p[j] || p[j] == '.'))
                dp[i][j] = can(i + 1, j + 1, s, p, n, m, dp);
            else
                dp[i][j] = false;
        }

        return dp[i][j];
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        return can(0, 0, s, p, n, m, dp);
    }
};