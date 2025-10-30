class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";

        int n = s.size();
        int startIdx = 0, maxLen = 1;

        auto palindromeLen = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }

            return r - l - 1;
        };

        for (int i = 0; i < n; i++) {
            int currLen = max(palindromeLen(i, i), palindromeLen(i, i + 1));

            if (currLen > maxLen) {
                maxLen = currLen;
                startIdx = i - (currLen - 1) / 2;
            }
        }

        return s.substr(startIdx, maxLen);
    }
};