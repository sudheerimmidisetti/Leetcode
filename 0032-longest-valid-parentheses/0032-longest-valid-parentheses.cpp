class Solution {
public:
    int longestValidParentheses(string s) {
        int i = 0, maxi = 0;
        int n = s.size();

        stack<int> st;
        st.push(-1);
        while (i < n) {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')') {
                st.pop();
                if (st.empty())
                    st.push(i);
                else
                    maxi = max(maxi, i - st.top());
            }
            i++;
        }

        return maxi;
    }
};
/*
-1, 0
*/