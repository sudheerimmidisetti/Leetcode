class Solution {
public:
    const long long MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> prefNum(n, 0), prefSum(n, 0), prefCnt(n, 0);
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                prefNum[i] = prefNum[i - 1];
                prefSum[i] = prefSum[i - 1];
                prefCnt[i] = prefCnt[i - 1];
            }

            if (s[i] != '0') {
                prefNum[i] = (prefNum[i] * 10 + (s[i] - '0')) % MOD;
                prefSum[i] += (s[i] - '0');
                prefCnt[i]++;
            }
        }

        vector<long long> pow10(n, 1);
        for (int i = 0; i < n; i++) {
            if (i > 0)
                pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        vector<int> res;
        for (auto& q : queries) {
            int cnt = prefCnt[q[1]] - (q[0] > 0 ? prefCnt[q[0] - 1] : 0);
            if (cnt == 0) {
                res.push_back(0);
                continue;
            }

            long long x = 0;
            if (q[0] > 0)
                x = (prefNum[q[1]] - (prefNum[q[0] - 1] * pow10[cnt]) % MOD + MOD) % MOD;
            else
                x = prefNum[q[1]];

            long long sum = prefSum[q[1]] - (q[0] > 0 ? prefSum[q[0] - 1] : 0);

            res.push_back((x * sum) % MOD);
        }

        return res;
    }
};