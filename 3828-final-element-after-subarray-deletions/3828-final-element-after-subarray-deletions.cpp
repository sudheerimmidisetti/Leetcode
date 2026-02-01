class Solution {
public:
    int finalElement(vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin(), nums.end());

        return max(nums[0], nums[n - 1]);
    }
};