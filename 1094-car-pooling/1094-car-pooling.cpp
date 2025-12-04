class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        sort(trips.begin(), trips.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[1] != b[1])
                     return a[1] < b[1];
                 return a[2] < b[2];
             });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int filledCapacity = 0;
        for (auto& t : trips) {
            while (!pq.empty() && pq.top().first <= t[1]) {
                filledCapacity -= pq.top().second;
                pq.pop();
            }

            if (filledCapacity + t[0] > capacity)
                return false;

            filledCapacity += t[0];
            pq.push({t[2], t[0]});
        }

        return true;
    }
};