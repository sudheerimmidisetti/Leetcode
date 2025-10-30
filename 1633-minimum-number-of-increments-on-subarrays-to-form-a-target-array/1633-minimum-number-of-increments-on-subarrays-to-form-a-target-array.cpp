class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int minOperations = target[0], prev = target[0];
        for (auto val : target) {
            if (val > prev)
                minOperations += (val - prev);
            
            prev = val;
        }

        return minOperations;
    }
};