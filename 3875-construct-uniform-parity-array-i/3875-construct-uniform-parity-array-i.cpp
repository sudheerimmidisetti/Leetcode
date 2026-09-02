class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        if (n == 1)
            return true;
        
        int even = 0, odd = 0;
        for (auto x : nums1) {
            if (x & 1)
                even++;
            else
                odd++;
        }

        if (odd == n || even == n)
            return true;

        bool flag1 = true;
        if (odd == 1)
            flag1 = false;

        bool flag2 = false;
        if (odd > 0 && even > 0)
            flag2 = true;

        return flag1 || flag2;
    }
};