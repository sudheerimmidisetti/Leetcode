class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        sort(s.begin(), s.end());

        int cntA = count(s.begin(), s.end(), 'a');
        if (cntA == n)
            return 0;

        return 26 - (s[cntA] - 'a');
    }
};