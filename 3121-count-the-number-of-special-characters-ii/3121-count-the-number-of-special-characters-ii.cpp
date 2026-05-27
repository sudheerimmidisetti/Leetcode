class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt = 0;

        vector<int> lstLower(26, -1), fstUpper(26, -1);
        for (int i = 0; i < word.size(); i++) {
            if (word[i] >= 'a' && word[i] <= 'z')
                lstLower[word[i] - 'a'] = i;
            else if (fstUpper[word[i] - 'A'] == -1)
                fstUpper[word[i] - 'A'] = i;
        }

        for (int i = 0; i < 26; i++) {
            if (lstLower[i] != -1 && fstUpper[i] != -1 && lstLower[i] < fstUpper[i])
                cnt++;
        }

        return cnt;
    }
};