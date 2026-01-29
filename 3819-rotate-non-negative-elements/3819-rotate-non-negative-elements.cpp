class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> positiveVal;
        for (auto& x : nums) {
            if (x >= 0)
                positiveVal.push_back(x);
        }

        if (positiveVal.size() == 0)
            return nums;

        k %= positiveVal.size();
        rotate(positiveVal.begin(), positiveVal.begin() + k, positiveVal.end());

        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0)
                nums[i] = positiveVal[idx++];
        }

        return nums;
    }
};