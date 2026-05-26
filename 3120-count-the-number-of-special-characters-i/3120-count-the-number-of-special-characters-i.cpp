class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> st(word.begin(), word.end());

        int cnt = 0;
        for (char c : word) {
            if (islower(c) && st.count(c) && st.count(toupper(c))) {
                st.erase(c);
                cnt++;
            }
        }

        return cnt;
    }
};