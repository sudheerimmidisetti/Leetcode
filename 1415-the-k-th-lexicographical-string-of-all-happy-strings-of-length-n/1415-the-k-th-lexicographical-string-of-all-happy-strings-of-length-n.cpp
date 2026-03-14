class Solution {
public:
    vector<string> res;
    void dfs(string s, int n) {
        if (s.size() == n) {
            res.push_back(s);
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (s.empty() || s.back() != ch)
                dfs(s + ch, n);
        }
    }

    string getHappyString(int n, int k) {
        dfs("", n);

        if (k > res.size())
            return "";
        return res[k - 1];
    }
};