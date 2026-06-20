class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        if (restrictions.empty())
            return n - 1;

        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());

        int sz = restrictions.size();
        if (restrictions[sz - 1][0] != n) {
            restrictions.push_back({n, n - 1});
            sz++;
        }

        for (int i = 1; i < sz; i++)
            restrictions[i][1] = min(restrictions[i][1],
                    restrictions[i - 1][1] + (restrictions[i][0] - restrictions[i - 1][0]));

        for (int i = sz - 2; i >= 0; i--)
            restrictions[i][1] = min(restrictions[i][1],
                    restrictions[i + 1][1] + (restrictions[i + 1][0] - restrictions[i][0]));

        int maxHeight = 0;
        for (int i = 0; i < sz - 1; i++)
            maxHeight = max(maxHeight, ((restrictions[i + 1][0] - restrictions[i][0]) +
                    restrictions[i][1] + restrictions[i + 1][1]) / 2);

        return maxHeight;
    }
};