class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            string str = "";
            str += s.substr(i, n);
            str += s.substr(0, i);

            if (str == goal)
                return true;
        }

        return false;
    }
};