class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int val = 1;
        n--;

        while (n) {
            string s = to_string(n);
            string s2 = to_string(val);

            if (count(s.begin(), s.end(), '0') == 0 && count(s2.begin(), s2.end(), '0') == 0)
                return {n, val};

            n--;
            val++;
        }

        return {-1, -1};
    }
};