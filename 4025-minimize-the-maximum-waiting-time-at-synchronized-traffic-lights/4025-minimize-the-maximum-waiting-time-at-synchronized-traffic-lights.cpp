class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxL = *max_element(lights.begin(), lights.end());

        int minPenalty = 0;
        for (auto& t : arrivalTime) {
            int r = t % period, minWaitingTime = INT_MAX;
            if (r < maxL)
                minWaitingTime = 0;
            else
                minWaitingTime = period - r;

            minPenalty = max(minPenalty, minWaitingTime);
        }

        return minPenalty;
    }
};