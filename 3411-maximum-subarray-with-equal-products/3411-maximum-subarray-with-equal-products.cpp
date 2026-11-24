class Solution {
public:
    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    int arrayLcm(const vector<int>& arr) {
        int res = arr[0];
        for (int i = 1; i < arr.size(); i++)
            res = lcm(res, arr[i]);

        return res;
    }

    int arrayGcd(const vector<int>& arr) {
        int res = arr[0];
        for (int i = 1; i < arr.size(); i++)
            res = gcd(res, arr[i]);

        return res;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();

        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            vector<int> subarray;
            int product = 1;

            for (int j = i; j < n; j++) {
                subarray.push_back(nums[j]);

                product *= nums[j] * 1LL;

                int gcdVal = arrayGcd(subarray);
                int lcmVal = arrayLcm(subarray);

                if (product == 1LL * gcdVal * lcmVal) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};