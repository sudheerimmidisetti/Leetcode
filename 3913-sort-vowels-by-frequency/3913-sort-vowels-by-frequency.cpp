class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();

        map<char, int> mp, idxs;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                mp[s[i]]++;
                if (!idxs.count(s[i]))
                    idxs[s[i]] = i;
            }
        }

        vector<char> v;
        for (auto x : mp)
            v.push_back(x.first);

        if (v.empty())
            return s;
        sort(v.begin(), v.end(), [&](char a, char b) {
            if (mp[a] != mp[b])
                return mp[a] > mp[b];
            return idxs[a] < idxs[b];
        });

        int j = 0, cnt = mp[v[j]];
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                s[i] = v[j];
                cnt--;

                if (cnt == 0) {
                    j++;

                    if (j < v.size())
                        cnt = mp[v[j]];
                }
            }
        }

        return s;
    }
};