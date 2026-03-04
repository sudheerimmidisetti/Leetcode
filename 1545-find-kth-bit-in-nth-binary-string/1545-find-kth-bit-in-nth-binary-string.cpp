class Solution {
public:
    string invert(string s) {
        string inverted;
        for (char ch : s) {
            inverted += (ch == '0' ? '1' : '0');
        }
        return inverted;
    }
    char findKthBit(int n, int k) {
        vector<string> s(n + 1);

        s[1] = "0";
        for (int i = 2; i < n + 1; i++) {
            string inverted = invert(s[i - 1]);
            reverse(inverted.begin(), inverted.end());
            s[i] = s[i - 1] + "1" + inverted;
        }

        return s[n][k - 1];
    }
};