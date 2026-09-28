class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;

        stack<char> st;
        for (char c : s) {
            if (c == '(')
                st.push(c);
            else if (c == ')')
                st.pop();

            maxDepth = max(maxDepth, (int)st.size());
        }

        return maxDepth;
    }
};