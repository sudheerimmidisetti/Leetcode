class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();

        map<int, int> mp;
        for (int x : nums)
            mp[x]++;

        map<int, int> mp2;
        for (auto x : mp)
            mp2[x.second]++;

        for (int i = 0; i < n; i++)
            if (mp2[mp[nums[i]]] == 1)
                return nums[i];

        return -1;
    }
};