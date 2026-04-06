class Solution {
public:
    int mirrorFrequency(string s) {
        int n = s.size();

        map<char, int>mp;
        for (auto x : s)
            mp[x]++;

        int cnt = 0;

        char i = 'a', j = 'z';
        while (i <= j)
            cnt += abs(mp[i++] - mp[j--]);

        i = '0', j = '9';
        while (i <= j)
            cnt += abs(mp[i++] - mp[j--]);

        return cnt;
    }
};