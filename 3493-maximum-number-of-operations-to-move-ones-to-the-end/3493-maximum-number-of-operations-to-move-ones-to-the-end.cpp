class Solution {
public:
    int maxOperations(string s) {
        int n = s.size() - 1;

        int cnt1 = 0, operations = 0;
        int i = 0;
        while (i < n) {
            if (s[i] == '0' && s[i + 1] == '1' && i != n)
                operations += cnt1;
            else if (s[i] == '1')
                cnt1++;

            i++;
        }

        if (s[n] == '0')
            operations += cnt1;

        return operations;
    }
};