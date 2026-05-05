class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        vector<long long> res(st.begin(), st.end());
        sort(res.begin(), res.end());

        if (n == 0)
            return 0;

        long long element = res[0];
        int len = 0;
        int maxLen = INT_MIN;
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == element) {
                element++;
                len++;
                maxLen = max(maxLen, len);
            } else {
                element = res[i] + 1;
                len = 1;
            }
        }

        return max(maxLen, len);
    }
};