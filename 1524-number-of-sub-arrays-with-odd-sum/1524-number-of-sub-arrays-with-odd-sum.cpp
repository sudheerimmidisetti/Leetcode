class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int n = arr.size();

        vector<int> prefixSum(n, 0);
        for (int i = 0; i < n; i++)
            prefixSum[i] = (i == 0) ? arr[i] : prefixSum[i - 1] + arr[i];

        int cnt = 0;
        int oddCnt = 0, evenCnt = 1;
        for (int i = 0; i < n; i++) {
            if (prefixSum[i] % 2 == 0) {
                cnt = (cnt + oddCnt) % MOD;
                evenCnt++;
            } else {
                cnt = (cnt + evenCnt) % MOD;
                oddCnt++;
            }
        }

        return cnt % MOD;
    }
};