class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        do {
            vector<int>arr;
            for (int num : nums) {
                arr.push_back(num);
            }
            res.push_back(arr);
        } while (next_permutation(nums.begin(), nums.end()));

        return res;
    }
};