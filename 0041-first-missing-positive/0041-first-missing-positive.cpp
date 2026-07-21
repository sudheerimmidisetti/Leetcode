class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        set<int> st(nums.begin(), nums.end());
        vector<int> res(st.begin(), st.end());

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                st.insert(nums[i]);
        }

        int missingInteger = 1;
        while (!st.empty()) {
            if (st.find(missingInteger) != st.end()) {
                st.erase(missingInteger);
                missingInteger++;
            } else
                break;
        }

        return missingInteger;
    }
};