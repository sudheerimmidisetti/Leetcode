class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        vector<int> st;

        long long cnt = 0;
        for (auto& x : nums) {
            cnt += lower_bound(st.begin(), st.end(), x) - st.begin();

            while (!st.empty() && st.back() > x)
                st.pop_back();

            st.push_back(x);
        }

        return cnt;
    }
};