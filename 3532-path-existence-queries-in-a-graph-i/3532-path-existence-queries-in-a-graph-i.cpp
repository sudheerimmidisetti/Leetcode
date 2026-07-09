class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int> v(n, 0);

        int x = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff)
                x++;

            v[i] = x;
        }

        vector<bool> res;
        for (auto& q : queries)
            res.push_back(v[q[0]] == v[q[1]]);

        return res;
    }
};