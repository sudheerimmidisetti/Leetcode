class Solution {
public:
    bool isValid(int num) {
        bool can = false;
        while (num > 0) {
            int d = num % 10;
            if (d == 3 || d == 4 || d == 7)
                return false;
            else if (d == 2 || d == 5 || d == 6 || d == 9)
                can = true;

            num /= 10;
        }

        return can;
    }

    int rotatedDigits(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (isValid(i))
                cnt++;
        }

        return cnt;
    }
};