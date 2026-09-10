class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        string curr = "";

        int num = 0;
        for (char c : s) {
            if (isdigit(c))
                num = num * 10 + (c - '0');
            else if (c == '[') {
                st.push({curr, num});
                curr = "";
                num = 0;
            } else if (c == ']') {
                auto p = st.top();
                st.pop();

                string repeated = "";
                for (int i = 0; i < p.second; i++)
                    repeated += curr;

                curr = p.first + repeated;
            } else
                curr += c;
        }

        return curr;
    }
};