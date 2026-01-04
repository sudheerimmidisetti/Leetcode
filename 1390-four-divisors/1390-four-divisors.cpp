class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        for (auto& val : nums) {
            int cnt = 0, currSum = 0;

            for (int i = 1; i <= (int)sqrt(val); i++) {
                if (val % i == 0) {
                    if (i == (int)(val / i)) {
                        cnt++;
                        currSum += i;
                    } else {
                        cnt += 2;
                        currSum += (i + (int)(val / i));
                    }

                    if (cnt > 4)
                        break;
                }
            }

            if (cnt == 4)
                totalSum += currSum;
        }

        return totalSum;
    }
};