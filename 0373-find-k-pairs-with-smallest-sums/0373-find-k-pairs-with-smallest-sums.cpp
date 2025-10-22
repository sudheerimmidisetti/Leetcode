class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int n2 = nums2.size();

        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty() || k == 0)
            return res;

        auto cmp = [&](const pair<int, pair<int, int>>& a,
                       const pair<int, pair<int, int>>& b) {
            return a.first > b.first;
        };

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, decltype(cmp)>
            pq(cmp);

        for (int i = 0; i < min(n, k); ++i)
            pq.push({nums1[i] + nums2[0], {i, 0}});

        while (k-- && !pq.empty()) {
            auto [sum, idx] = pq.top();
            pq.pop();

            int i = idx.first, j = idx.second;
            res.push_back({nums1[i], nums2[j]});

            if (j + 1 < n2)
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
        }

        return res;
    }
};