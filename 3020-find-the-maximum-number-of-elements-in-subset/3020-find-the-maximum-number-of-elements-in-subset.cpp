class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<long long, int> mp;
        for (int x : nums)
            mp[x]++;

        int maxCnt = 0;
        if (mp[1] & 1)
            maxCnt = mp[1];
        else
            maxCnt = mp[1] - 1;

        mp.erase(1);
        for (auto& p : mp) {
            int cnt = 0;
            long long x = p.first;

            while (mp[x] > 1) {
                cnt += 2;
                x *= x;
            }

            maxCnt = max(maxCnt, cnt + ((mp[x] > 0) ? 1 : -1));
        }

        return maxCnt;
    }
};