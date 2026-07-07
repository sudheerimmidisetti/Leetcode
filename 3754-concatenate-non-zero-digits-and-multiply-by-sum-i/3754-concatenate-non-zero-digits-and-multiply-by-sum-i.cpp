class Solution {
public:
    long long sumAndMultiply(int n) {
        string x = to_string(n);
        int sum = 0;

        string s = "";
        for (auto& c : x) {
            if (c != '0') {
                s += c;
                sum += c - '0';
            }
        }

        if (s.empty())
            return 0;
        
        return 1LL * stoll(s) * sum;
    }
};