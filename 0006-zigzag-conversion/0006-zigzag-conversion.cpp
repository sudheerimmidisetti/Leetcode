class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows == 1)
            return s;

        string str = "";
        int left = (numRows - 1) * 2, right = 0;
        for (int i = 0; i < numRows; i++) {
            int j = i;

            bool flag = true;
            while (j < n) {
                str += s[j];

                if (i == 0 || i == numRows - 1) {
                    j += max(left, right);
                } else {
                    if (flag) {
                        j += left;
                        flag = false;
                    } else {
                        j += right;
                        flag = true;
                    }
                }
            }

            left -= 2;
            right += 2;
        }

        return str;
    }
};