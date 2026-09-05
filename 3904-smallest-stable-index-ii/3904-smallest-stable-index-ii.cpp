class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> suffMin(n, 0);

        suffMin[n - 1] = nums.back();
        for (int i = n - 2; i >= 0; i--)
            suffMin[i] = min(suffMin[i + 1], nums[i]);

        int prefMax = 0;
        for (int i = 0; i < n; i++) {
            prefMax = max(prefMax, nums[i]);
            if (prefMax - suffMin[i] <= k)
                return i;
        }

        return -1;
    }
};