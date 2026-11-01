class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        
        int minMoves = 0;
        for (int x : nums)
            minMoves += (x - mini);
        
        return minMoves;
    }
};