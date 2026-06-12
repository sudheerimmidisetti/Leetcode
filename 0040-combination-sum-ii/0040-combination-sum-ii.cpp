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
        solve(idx + 1, target - candidates[idx], candidates, curr);
        curr.pop_back();

        int nxt = idx + 1;
        while (nxt < candidates.size() && candidates[nxt] == candidates[idx])
            nxt++;

        solve(nxt, target, candidates, curr);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> curr;
        solve(0, target, candidates, curr);

        return res;
    }
};