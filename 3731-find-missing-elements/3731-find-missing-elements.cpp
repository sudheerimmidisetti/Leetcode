class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int maxi = nums[n - 1];
        int mini = nums[0];

        vector<int> res;
        for (int x = mini + 1; x < maxi; x++) {
            if (!count(nums.begin(), nums.end(), x))
                res.push_back(x);
        }

        return res;
    }
};