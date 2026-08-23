class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int half = n / 2;

        int lSum = 0, lCnt = 0;
        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                lCnt++;
            else
                lSum += (num[i] - '0');
        }

        int rSum = 0, rCnt = 0;
        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                rCnt++;
            else
                rSum += (num[i] - '0');
        }

        if ((lCnt + rCnt) & 1)
            return true;

        return (lSum - rSum) != (9 * (rCnt - lCnt) / 2);
    }
};