class Solution {
public:
    vector<vector<int>> res;

    void solve(int idx, int target, vector<int>& candidates, vector<int>& curr) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        if (target < 0 || idx == candidates.size())
            return;

        curr.push_back(candidates[idx]);
        solve(idx, target - candidates[idx], candidates, curr);
        curr.pop_back();

        solve(idx + 1, target, candidates, curr);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        solve(0, target, candidates, curr);

        return res;
    }
};