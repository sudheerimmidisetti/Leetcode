class Solution {
public:
    int findNthDigit(int n) {
        long long digitLen = 1, cnt = 9, start = 1;

        while (n > (digitLen * cnt)) {
            n -= (digitLen * cnt);

            digitLen += 1;
            cnt *= 10;
            start *= 10;
        }

        long long num = start + ((n - 1) / digitLen);
        long long idx = (n - 1) % digitLen;

        string s = to_string(num);

        return s[idx] - '0';
    }
};