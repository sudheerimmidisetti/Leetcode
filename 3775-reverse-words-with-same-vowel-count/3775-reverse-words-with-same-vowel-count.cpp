class Solution {
public:
    int vowelCnt(string s) {
        int cnt = 0;
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                cnt++;
        }

        return cnt;
    }
    string reverseWords(string s) {
        vector<string> words;
        string tmp;
        for (char c : s) {
            if (c == ' ') {
                words.push_back(tmp);
                tmp.clear();
            } else
                tmp += c;
        }
        words.push_back(tmp);

        int firstWordVowelCnt = vowelCnt(words[0]);
        bool firstWord = true;
        for (auto& w : words) {
            if (firstWord) {
                firstWord = false;
                continue;
            } else if (vowelCnt(w) == firstWordVowelCnt)
                reverse(w.begin(), w.end());
        }

        string res = "";
        for (int i = 0; i < words.size(); i++) {
            if (i > 0)
                res += " ";
            res += words[i];
        }

        return res;
    }
};