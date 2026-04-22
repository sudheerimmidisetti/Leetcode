class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;

        for (int i = n - (k % n); i < n; i++) {
            res.push_back(nums[i]);
        }
        for (int i = 0; i < n - (k % n); i++) {
            res.push_back(nums[i]);
        }

        for (int i = 0; i < n; i++) {
            nums[i] = res[i];
        }
    }
};