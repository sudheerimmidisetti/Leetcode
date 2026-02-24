class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();

        int diff = 0;
        bool player1 = true;
        for (int i = 0; i < n; i++) {
            if ((i + 1) % 6 == 0)
                player1 = !player1;

            if (nums[i] & 1) {
                player1 = !player1;
                if (player1)
                    diff += nums[i];
                else
                    diff -= nums[i];
            } else if (player1)
                diff += nums[i];
            else
                diff -= nums[i];
        }

        return diff;
    }
};