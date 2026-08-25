class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> st(nums.begin(), nums.end());

        int minVal = INT_MAX;
        for (int i = 1; i <= (k * 101); i++) {
            if (st.find(k * i) == st.end()) {
                minVal = k * i;
                break;
            }
        }

        return minVal;
    }
};