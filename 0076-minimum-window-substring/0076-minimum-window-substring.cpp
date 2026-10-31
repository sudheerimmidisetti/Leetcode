class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) {
            return "";
        }

        unordered_map<char, int> dictT;
        for (char c : t) {
            dictT[c]++;
        }

        int required = dictT.size();
        int formed = 0;

        unordered_map<char, int> dictS;
        int l = 0, r = 0;
        int start = -1, minLen = 0;
        while(r < s.size()) {
            char c = s[r];
            dictS[c]++;

            if (dictT.find(c) != dictT.end() && dictS[c] == dictT[c]) {
                formed++;
            }

            while (l <= r && formed == required) {
                c = s[l];
                
                if (start == -1 || (r - l + 1) < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                dictS[c]--;
                if (dictT.find(c) != dictT.end() && dictS[c] < dictT[c]) {
                    formed--;
                }

                l++;
            }

            r++;
        }

        return start == -1 ? "" : s.substr(start, minLen);
    }
};