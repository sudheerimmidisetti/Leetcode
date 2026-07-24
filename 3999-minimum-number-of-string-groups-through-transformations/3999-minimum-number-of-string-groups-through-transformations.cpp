class Solution {
public:
    string minString(string& s) {
        s += s;

        int n = s.size() / 2, i = 0, j = 1, k = 0;
        while (i < n && j < n && k < n) {
            if (s[i + k] == s[j + k])
                k++;
            else if (s[i + k] > s[j + k]) {
                i = i + k + 1;
                if (i <= j)
                    i = j + 1;
                
                k = 0;
            } else {
                j = j + k + 1;
                if (j <= i)
                    j = i + 1;
                
                k = 0;
            }
        }

        return s.substr(min(i, j), n);
    }

    int minimumGroups(vector<string>& words) {
        unordered_set<string> groups;

        for (auto& w : words) {
            string oddString, evenString;
            for (int i = 0; i < w.size(); i++) {
                if (i & 1)
                    oddString += w[i];
                else
                    evenString += w[i];
            }

            groups.insert(minString(oddString) + "#" + minString(evenString));
        }

        return groups.size();
    }
};