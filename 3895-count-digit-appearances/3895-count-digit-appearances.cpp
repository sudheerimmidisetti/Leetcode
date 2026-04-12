class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int cnt = 0;

        for (auto x : nums) {
            while (x) {
                int val = x % 10;
                x /= 10;

                if (val == digit)
                    cnt++;
            }
        }

        return cnt;
    }
};