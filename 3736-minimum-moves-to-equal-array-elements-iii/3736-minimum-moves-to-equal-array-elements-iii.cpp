class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());

        int minMovesCnt = 0;
        for (auto val : nums)
            minMovesCnt += (maxEle - val);

        return minMovesCnt;
    }
};