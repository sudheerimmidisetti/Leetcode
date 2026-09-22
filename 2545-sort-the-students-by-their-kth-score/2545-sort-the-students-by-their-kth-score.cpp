class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int m = score.size(), n = score[0].size();

        map<int, int, greater<int>> mp;
        for (int i = 0; i < m; i++)
            mp[score[i][k]] = i;

        vector<vector<int>> res;
        for (auto &[val, idx] : mp)
            res.push_back(score[idx]);

        return res;
    }
};