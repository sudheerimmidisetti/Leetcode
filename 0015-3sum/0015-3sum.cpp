class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if ((nums[i] + nums[j] + nums[k]) == 0) {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if ((nums[i] + nums[j] + nums[k]) > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        for (auto p : s) {
            res.push_back(p);
        }
        return res;
    }
};