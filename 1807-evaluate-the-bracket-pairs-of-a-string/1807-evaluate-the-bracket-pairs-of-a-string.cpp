class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& x : knowledge)
            mp[x[0]] = x[1];

        bool can = false;

        string key = "", res = "";
        for (char c : s) {
            if (c == '(')
                can = true;
            else if (c == ')') {
                if (mp.count(key))
                    res += mp[key];
                else
                    res.push_back('?');

                can = false;
                key.clear();
            } else if (can)
                key.push_back(c);
            else
                res.push_back(c);
        }

        return res;
    }
};