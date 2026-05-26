class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> st(word.begin(), word.end());

        int cnt = 0;
        for (char c : word) {
            if (islower(c) && st.find(c) != st.end() && st.find(toupper(c)) != st.end()) {
                st.erase(c);
                cnt++;
            }
        }

        return cnt;
    }
};