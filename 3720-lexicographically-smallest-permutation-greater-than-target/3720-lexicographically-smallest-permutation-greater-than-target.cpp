class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> mp(26, 0);
        for (auto& c : s)
            mp[c - 'a']++;

        string res;
        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            if (mp[x] > 0) {
                res += target[i];
                mp[x]--;
                continue;
            }

            for (int c = x + 1; c < 26; c++) {
                if (mp[c] > 0) {
                    res += char('a' + c);
                    mp[c]--;

                    for (int k = 0; k < 26; k++)
                        res.append(mp[k], char('a' + k));

                    return res;
                }
            }

            break;
        }

        n = res.size();
        for (int i = n - 1; i >= 0; i--) {
            int x = res[i] - 'a';
            mp[x]++;

            for (int c = x + 1; c < 26; c++) {
                if (mp[c] > 0) {
                    string res2 = res.substr(0, i);
                    res2 += char('a' + c);
                    mp[c]--;

                    for (int k = 0; k < 26; k++)
                        res2.append(mp[k], char('a' + k));

                    return res2;
                }
            }
        }

        return "";
    }
};