class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for (auto& r : grid) {
            for (int v : r)
                arr.push_back(v);
        }

        int k = arr[0];
        for (int v : arr) {
            if (abs(v - k) % x != 0)
                return -1;
        }

        sort(arr.begin(), arr.end());

        int median = arr[arr.size() / 2];

        int minOperations = 0;
        for (int v : arr)
            minOperations += abs(v - median) / x;

        return minOperations;
    }
};