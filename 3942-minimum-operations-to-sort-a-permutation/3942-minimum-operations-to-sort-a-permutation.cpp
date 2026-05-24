class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int minOps = INT_MAX;

        bool can = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (nums[0] + i) % n) {
                can = false;
                break;
            }
        }

        if (can)
            minOps = min({minOps, (n - nums[0]) % n, nums[0] + 2});

        reverse(nums.begin(), nums.end());

        can = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (nums[0] + i) % n) {
                can = false;
                break;
            }
        }

        if (can)
            minOps = min({minOps, 1 + ((n - nums[0]) % n), nums[0] + 1});

        return minOps == INT_MAX ? -1 : minOps;
    }
};