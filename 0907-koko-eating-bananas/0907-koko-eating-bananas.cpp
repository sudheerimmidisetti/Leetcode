class Solution {
public:
    long long canK(vector<int>& piles, int k) {
        long long sum = 0;
        for (auto& num : piles)
            sum += ((long long)num + k - 1) / k;

        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        int minCnt = r;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (canK(piles, mid) <= h) {
                minCnt = min(minCnt, mid);
                r = mid - 1;
            } else
                l = mid + 1;
        }

        return minCnt;
    }
};