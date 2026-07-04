class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> v(n + 1);
        for (auto& r : roads) {
            v[r[0]].push_back({r[1], r[2]});
            v[r[1]].push_back({r[0], r[2]});
        }

        vector<bool> vist(n + 1, false);
        int minScore = INT_MAX;

        queue<int> q;
        q.push(1);
        vist[1] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (auto& [y, z] : v[x]) {
                minScore = min(minScore, z);

                if (!vist[y]) {
                    vist[y] = true;
                    q.push(y);
                }
            }
        }

        return minScore;
    }
};