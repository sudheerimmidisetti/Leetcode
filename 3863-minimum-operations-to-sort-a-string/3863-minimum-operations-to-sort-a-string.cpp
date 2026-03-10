class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        string t = s;
        sort(t.begin(), t.end());

        if (s == t)
            return 0;
        else if (n <= 2)
            return -1;
        else if (s[0] == t[0] || s[n - 1] == t[n - 1])
            return 1;

        map<char, int> mp;
        for (auto& c : s) {
            if (c == t[0])
                mp[c]++;
            else if (c == t[n - 1])
                mp[c]++;
        }

        if (s[0] == t[n - 1] && s[n - 1] == t[0] && mp[t[0]] == 1 &&
            mp[t[n - 1]] == 1)
            return 3;
        else
            return 2;
    }
};