class Solution {
public:
    int partitionString(string s) {
        set<char> st;

        int cnt = 0;
        for (auto& c : s) {
            if (st.find(c) != st.end()) {
                cnt++;
                st.clear();
            }
            
            st.insert(c);
        }

        return cnt + 1;
    }
};