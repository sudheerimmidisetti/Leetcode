class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i' ||
                c == 'A' || c == 'E' || c == 'O' || c == 'U' || c == 'I');
    }

    string sortVowels(string s) {
        int n = s.size();

        string tmpS = "";
        for (auto c : s) {
            if (isVowel(c))
                tmpS += c;
        }
        sort(tmpS.begin(), tmpS.end());

        int j = 0;
        string res = "";
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                res += tmpS[j];
                j++;
            } else
                res += s[i];
        }

        return res;
    }
};