#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;
    int divisibleGame(vector<int>& nums) {
        set<int> st;
        st.insert(2);
        for (auto& x : nums) {
            int tmp = x;
            for (int i = 2; 1LL * i * i <= tmp; i++) {
                if (tmp % i == 0) {
                    st.insert(i);
                    while (tmp % i == 0)
                        tmp /= i;
                }
            }

            if (tmp > 1)
                st.insert(tmp);
        }

        vector<int> v(st.begin(), st.end());

        long long maxSum = LLONG_MIN;
        int k = -1;

        for (auto& x : v) {
            long long currSum = 0, maxCurrSum = LLONG_MIN;

            for (auto& y : nums) {

                if (y % x == 0) {
                    currSum = max(y * 1ll, currSum + y);
                    maxCurrSum = max(maxCurrSum, currSum);
                } else {
                    y *= (-1);
                    currSum = max(y * 1ll, currSum + y);
                    maxCurrSum = max(maxCurrSum, currSum);

                    y *= (-1);
                }
            }

            if (maxSum < maxCurrSum ||
                (maxSum == maxCurrSum && (k == -1 || x < k))) {
                maxSum = maxCurrSum;
                k = x;
            }
        }

        maxSum = (maxSum % MOD + MOD) % MOD;
        return (maxSum * k) % MOD;
    }
};