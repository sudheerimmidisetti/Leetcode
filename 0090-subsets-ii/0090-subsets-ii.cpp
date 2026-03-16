class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();

        set<vector<int>>st;
        int total = 1 << n;
        for(int mask = 0; mask < total; mask++) {
            vector<int>subSet;
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    subSet.push_back(nums[i]);
                }
            }

            sort(subSet.begin(), subSet.end());
            st.insert(subSet);
        }

        vector<vector<int>>res(st.begin(), st.end());

        return res;
    }
};