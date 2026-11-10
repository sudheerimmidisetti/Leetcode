class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> vec(n + 1, INT_MAX);
        
        vec[0] = 0;
        for (int i = 0; i < n + 1; i++) {
            for (int j = 1; j < 4; j++) {
                if ((i + j) < n + 1)
                    vec[i + j] = min(vec[i + j], (vec[i] + (costs[i + j - 1] + (j * j))));
            }
        }

        return vec[n];
    }
};