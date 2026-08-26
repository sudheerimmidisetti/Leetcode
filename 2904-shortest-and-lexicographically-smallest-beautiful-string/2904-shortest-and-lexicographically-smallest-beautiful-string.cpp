class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int l = 0, onesCnt = 0;
        
        string resStr = "";
        for (int r = 0; r < n; r++) {
            if (s[r] == '1')
                onesCnt++;

            while (onesCnt > k) {
                if (s[l] == '1')
                    onesCnt--;

                l++;
            }

            if (onesCnt == k) {
                while (l <= r && s[l] == '0')
                    l++;

                string currStr = s.substr(l, r - l + 1);
                if (resStr == "" || currStr.size() < resStr.size() ||
                    (currStr.size() == resStr.size() && currStr < resStr)) {
                    resStr = currStr;
                }
            }
        }

        return resStr;
    }
};