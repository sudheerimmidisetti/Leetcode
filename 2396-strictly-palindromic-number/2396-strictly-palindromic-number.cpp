class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for (int i = 2; i <= n - 2; i++) {
            int tmp = n;

            string d = "";
            while (tmp > 0) {
                d = to_string(tmp % i) + d;
                tmp /= i;
            }

            string rev = d;
            reverse(rev.begin(), rev.end());

            if (d != rev)
                return false;
        }

        return true;
    }
};