class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for (auto q : queries)
            for (int i = q[0]; i <= q[1]; i += q[2])
                nums[i] = 1ll * nums[i] * q[3] % (int)(1e9 + 7);

        int res = 0;
        for (auto x : nums)
            res ^= x;

        return res;
    }
};