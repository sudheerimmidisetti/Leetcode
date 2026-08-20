class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> v1, v2;
        v1.push_back(nums[0]);
        v2.push_back(nums[1]);

        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < n; i++) {
            int idx1 = upper_bound(arr1.begin(), arr1.end(), nums[i]) - arr1.begin();
            int idx2 = upper_bound(arr2.begin(), arr2.end(), nums[i]) - arr2.begin();

            if ((arr1.size() - idx1) > (arr2.size() - idx2)) {
                v1.push_back(nums[i]);
                arr1.insert(arr1.begin() + idx1, nums[i]);
            } else if ((arr1.size() - idx1) < (arr2.size() - idx2)) {
                v2.push_back(nums[i]);
                arr2.insert(arr2.begin() + idx2, nums[i]);
            } else if (v1.size() <= v2.size()) {
                v1.push_back(nums[i]);
                arr1.insert(arr1.begin() + idx1, nums[i]);
            } else {
                v2.push_back(nums[i]);
                arr2.insert(arr2.begin() + idx2, nums[i]);
            }
        }

        v1.insert(v1.end(), v2.begin(), v2.end());
        return v1;
    }
};