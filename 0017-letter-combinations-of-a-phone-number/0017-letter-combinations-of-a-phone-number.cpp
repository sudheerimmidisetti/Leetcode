class Solution {
public:
    vector<string> res;

    void solve(int idx, string& digits, map<char, string>& mp, string& str) {
        if (digits.size() == idx) {
            res.push_back(str);
            return;
        }

        for (int i = 0; i < mp[digits[idx]].size(); i++) {
            str += mp[digits[idx]][i];
            solve(idx + 1, digits, mp, str);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        map<char, string> mp = {{'0', ""},    {'1', ""},     {'2', "abc"},
                                {'3', "def"}, {'4', "ghi"},  {'5', "jkl"},
                                {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"},
                                {'9', "wxyz"}};

        string str;
        solve(0, digits, mp, str);

        return res;
    }
};