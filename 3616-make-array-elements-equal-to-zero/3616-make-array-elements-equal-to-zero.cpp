class Solution {
public:
    bool simulate(int curr, int direction, vector<int>& nums) {
        int n = nums.size();

        vector<int> numsCpy = nums;
        while (curr >= 0 && curr < n) {
            if (numsCpy[curr] == 0)
                curr += direction;
            else {
                numsCpy[curr]--;
                direction *= -1;
                curr += direction;
            }
        }

        for (int num : numsCpy) {
            if (num != 0)
                return false;
        }

        return true;
    }

    int countValidSelections(vector<int>& nums) {
        int n = nums.size();

        int validCnt = 0;
        for (int curr = 0; curr < n; ++curr) {
            if (nums[curr] == 0) {
                if (simulate(curr, 1, nums))
                    validCnt++;
            }

            if (nums[curr] == 0) {
                if (simulate(curr, -1, nums))
                    validCnt++;
            }
        }

        return validCnt;
    }
};