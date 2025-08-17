class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int res = (1 << 30) - 1;
        
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                res &= i;
                flag = false;
            }
        }

        return flag ? 0 : res;
    }
};
