class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size(), idx = 1;

        while (idx < n && nums[idx - 1] < nums[idx])
            idx++;

        int p = idx - 1;
        while (idx < n && nums[idx - 1] > nums[idx])
            idx++;

        int q = idx - 1;
        while (idx < n && nums[idx - 1] < nums[idx])
            idx++;

        return (p != 0) && (q != p) && ((idx - 1) == (n - 1)) && ((idx - 1) != q);
    }
};