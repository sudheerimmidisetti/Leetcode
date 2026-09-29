class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum = 0, maxi = 0;
        for (int x : milestones) {
            sum += x;
            maxi = max(maxi, (long long)x);
        }

        return min(sum, 2 * (sum - maxi) + 1);
    }
};
