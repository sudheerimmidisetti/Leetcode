class Solution {
public:
    void parenthesis(vector<string>& res, string curr, int openBracketCnt,
                     int closedBracketCnt, int n) {
        if (openBracketCnt == n && closedBracketCnt == n) {
            res.push_back(curr);
            return;
        }

        if (openBracketCnt < n)
            parenthesis(res, curr + "(", openBracketCnt + 1, closedBracketCnt, n);

        if (closedBracketCnt < openBracketCnt)
            parenthesis(res, curr + ")", openBracketCnt, closedBracketCnt + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        parenthesis(res, "", 0, 0, n);

        return res;
    }
};