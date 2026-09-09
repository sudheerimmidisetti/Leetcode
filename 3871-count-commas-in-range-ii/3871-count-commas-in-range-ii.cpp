class Solution {
public:
    long long countCommas(long long n) {
        long long cnt = 0;

        if (n >= 1000LL)
            cnt += (min(n, 999999LL) - 1000LL + 1) * 1;
        
        if (n >= 1000000LL)
            cnt += (min(n, 999999999LL) - 1000000LL + 1) * 2;
        
        if (n >= 1000000000LL)
            cnt += (min(n, 999999999999LL) - 1000000000LL + 1) * 3;
        
        if (n >= 1000000000000LL)
            cnt += (min(n, 999999999999999LL) - 1000000000000LL + 1) * 4;

        if (n >= 1000000000000000LL)
            cnt += (n - 999999999999999LL) * 5;

        return cnt;
    }
};