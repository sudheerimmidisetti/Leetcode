class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0, cnt = 0;
        for (auto& x : nums) {
            sum += x;

            int rem = ((sum % k) + k) % k;
            cnt += mp[rem];

            mp[rem]++;
        }

        return cnt;
    }
};