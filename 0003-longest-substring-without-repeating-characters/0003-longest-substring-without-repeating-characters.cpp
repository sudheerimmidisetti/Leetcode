class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int maxLen = 0;
        unordered_set<char> st;
        int start = 0;
        for (int end = 0; end < n; end++) {
            while (st.find(s[end]) != st.end()) {
                st.erase(s[start]);
                start++;
            }
            st.insert(s[end]);

            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};