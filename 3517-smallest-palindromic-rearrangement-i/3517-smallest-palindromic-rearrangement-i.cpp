class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if (n == 1 || n == 2)
            return s;

        string str = s.substr(0, n / 2);
        sort(str.begin(), str.end());

        string rev = str;
        reverse(rev.begin(), rev.end());

        if ((n % 2) == 1)
            str += s[n / 2];

        return str + rev;
    }
};