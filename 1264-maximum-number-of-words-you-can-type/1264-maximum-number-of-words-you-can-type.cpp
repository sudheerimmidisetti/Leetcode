class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);

        string word;
        vector<string> words;
        while (ss >> word)
            words.push_back(word);

        int cnt = 0;
        for (auto w : words) {
            for (char c : w) {
                if (count(brokenLetters.begin(), brokenLetters.end(), c) > 0) {
                    cnt++;
                    break;
                }
            }
        }

        return words.size() - cnt;
    }
};