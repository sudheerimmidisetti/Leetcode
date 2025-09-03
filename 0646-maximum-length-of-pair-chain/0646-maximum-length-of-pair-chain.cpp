class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });

        int cnt = 0, currEnd = INT_MIN;
        for (auto& p : pairs) {
            if (p[0] > currEnd) {
                cnt++;
                currEnd = p[1];
            }
        }
        return cnt;
    }
};