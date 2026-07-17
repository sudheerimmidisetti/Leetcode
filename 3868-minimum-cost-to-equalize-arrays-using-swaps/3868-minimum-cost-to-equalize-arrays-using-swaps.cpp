class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        for (int x : nums1)
            mp[x]++;

        for (int x : nums2)
            mp[x]--;

        int minCost = 0;
        for (auto [val, cnt] : mp) {
            if ((cnt & 1))
                return -1;
            
            if (cnt > 0)
                minCost += (cnt / 2);
        }
        
        return minCost;
    }
};