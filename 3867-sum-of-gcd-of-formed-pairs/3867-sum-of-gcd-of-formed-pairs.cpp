class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefGcd(n);

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            prefGcd[i] = std::gcd(maxi, nums[i]);
        }
        sort(prefGcd.begin(), prefGcd.end());

        long long sum = 0;
        int l = 0, r = n - 1;
        while (l < r) {
            sum += std::gcd(prefGcd[l], prefGcd[r]);
            l++;
            r--;
        }

        return sum;
    }
};