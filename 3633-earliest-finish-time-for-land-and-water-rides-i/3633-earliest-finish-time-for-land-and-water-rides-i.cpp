class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();

        int minTime = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int land_water = max((landStartTime[i] + landDuration[i]),
                                     waterStartTime[j]) + waterDuration[j];

                int water_land = max((waterStartTime[j] + waterDuration[j]),
                                     landStartTime[i]) + landDuration[i];

                minTime = min({minTime, land_water, water_land});
            }
        }

        return minTime;
    }
};