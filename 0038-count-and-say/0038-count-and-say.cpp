class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";

        string s = "1";
        for (int i = 2; i <= n; i++) {
            string tmpry = "";
            int len = s.size();
            int cnt = 1;
            for (int j = 0; j < len; j++) {
                if (s[j] == s[j + 1])
                    cnt++;
                else {
                    tmpry += to_string(cnt);
                    tmpry += s[j];
                    cnt = 1;
                }
            }
            s = tmpry;
        }
        return s;
    }
};