class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        vector<int> zeroCnt;

        int ttlOnes = 0, i = 0;
        while (i < n) {
            int j = i;
            while (j < s.size() && s[j] == s[i])
                j++;

            if (s[i] == '1')
                ttlOnes += j - i;
            else
                zeroCnt.push_back(j - i);

            i = j;
        }

        int maxZeros = 0;
        for (int i = 0; i + 1 < zeroCnt.size(); i++)
            maxZeros = max(maxZeros, zeroCnt[i] + zeroCnt[i + 1]);

        return ttlOnes + maxZeros;
    }
};