class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();

        vector<int> res;
        for (int i = 0; i < n; i++) {
            res.push_back(nums[i]);

            while (res.size() > 1 && gcd(res.back(), res[res.size() - 2]) > 1) {
                long long a = res.back();
                long long b = res[res.size() - 2];

                res.pop_back();
                res.pop_back();

                res.push_back(lcm(a, b));
            }
        }
        return res;
    }
};