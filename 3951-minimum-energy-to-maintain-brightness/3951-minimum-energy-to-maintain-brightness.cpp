class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        int sz = intervals.size();
        sort(intervals.begin(), intervals.end());

        long long time = 0;

        int l = intervals[0][0], r = intervals[0][1];
        for (int i = 1; i < sz; i++) {
            if (intervals[i][0] <= r + 1)
                r = max(r, intervals[i][1]);
            else {
                time += (long long)(r - l + 1);
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }

        time += (long long)(r - l + 1);

        return (time * ((brightness + 2) / 3));
    }
};