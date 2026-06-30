class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        map<char, int> mp;

        int l = 0, r = 0, cnt = 0;
        while (r < n) {
            mp[s[r]]++;

            while (mp['a'] && mp['b'] && mp['c']) {
                cnt += (n - r);

                mp[s[l]]--;
                l++;
            }

            r++;
        }

        return cnt;
    }
};