class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int wavesCnt = 0;

        for (int i = num1; i <= num2; i++) {
            string s = to_string(i);

            int sz = s.size();
            if (sz < 3)
                continue;

            int waves = 0;
            for (int j = 1; j < sz - 1; j++) {
                if ((s[j] - '0') > (s[j - 1] - '0') &&
                    (s[j] - '0') > (s[j + 1] - '0'))
                    waves++;
                else if ((s[j] - '0') < (s[j - 1] - '0') &&
                         (s[j] - '0') < (s[j + 1] - '0'))
                    waves++;
            }

            wavesCnt += waves;
        }

        return wavesCnt;
    }
};