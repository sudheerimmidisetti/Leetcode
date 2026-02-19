class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();

        int totalCnt = 0, currCnt = 1, prevCnt = 0;
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == s[i])
                currCnt++;
            else {
                totalCnt += min(currCnt, prevCnt);
                prevCnt = currCnt;
                currCnt = 1;
            }
        }
        totalCnt += min(currCnt, prevCnt);

        return totalCnt;
    }
};