class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        int cnt = 0;
        auto palindromeLen = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                cnt++;
                l--;
                r++;
            }
        };

        for (int i = 0; i < n; i++) {
            palindromeLen(i, i);
            palindromeLen(i, i + 1);
        }

        return cnt;
    }
};