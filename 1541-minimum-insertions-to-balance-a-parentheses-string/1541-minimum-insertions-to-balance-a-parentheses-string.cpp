class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        int insertions = 0, openCnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                openCnt++;
            } else {
                if (i + 1 < n && s[i + 1] == ')')
                    i++;
                else
                    insertions++;

                if (openCnt > 0)
                    openCnt--;
                else
                    insertions++;
            }
        }

        return insertions + (2 * openCnt);
    }
};