class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> idxs;

        string res;
        for (char c : s) {
            if (c == '(')
                idxs.push(res.length());
            else if (c == ')') {
                reverse(res.begin() + idxs.top(), res.end());
                idxs.pop();
            } else
                res += c;
        }

        return res;
    }
};
