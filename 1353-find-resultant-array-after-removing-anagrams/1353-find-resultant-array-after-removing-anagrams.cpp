class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();

        string s1 = words[0], s2 = "";
        sort(s1.begin(), s1.end());

        for (int i = 1; i < n; i++) {
            s2 = words[i];
            sort(s2.begin(), s2.end());

            if (s2 == s1)
                words[i].clear();
            else
                s1 = s2;
        }

        vector<string> res;
        for (string c : words) {
            if (c.size() > 0)
                res.push_back(c);
        }

        return res;
    }
};