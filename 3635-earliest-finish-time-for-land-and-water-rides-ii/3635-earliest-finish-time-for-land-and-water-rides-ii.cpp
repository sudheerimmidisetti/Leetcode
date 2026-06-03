class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();

        int minTime = INT_MAX;

        int minLand = INT_MAX;
        for (int i = 0; i < n; i++)
            minLand = min(minLand, landStartTime[i] + landDuration[i]);

        int minWater = INT_MAX;
        for (int i = 0; i < m; i++) {
            minWater = min(minWater, waterStartTime[i] + waterDuration[i]);
            minTime = min(minTime, max(minLand, waterStartTime[i]) + waterDuration[i]);
        }

        for (int i = 0; i < n; i++)
            minTime = min(minTime, max(minWater, landStartTime[i]) + landDuration[i]);

        return minTime;
    }
};