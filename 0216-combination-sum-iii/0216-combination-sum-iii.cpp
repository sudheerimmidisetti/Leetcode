class Solution {
public:
    vector<vector<int>> res;

    void solve(int k, int target, int num, vector<int> curr) {
        if (target == 0 && curr.size() == k) {
            res.push_back(curr);
            return;
        }

        if (target < 0 || curr.size() > k || num > 9)
            return;

        if (num <= 9) {
            curr.push_back(num);
            solve(k, target - num, num + 1, curr);
            curr.pop_back();

            solve(k, target, num + 1, curr);
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        solve(k, n, 1, curr);

        return res;
    }
};