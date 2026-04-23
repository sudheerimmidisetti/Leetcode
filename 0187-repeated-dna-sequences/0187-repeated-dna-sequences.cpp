class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();

        if (n < 10)
            return {};

        map<string, int> mp;
        for (int i = 0; i <= n - 10; i++)
            mp[s.substr(i, 10)]++;

        vector<string> res;
        for (auto& word : mp) {
            if (word.second > 1)
                res.push_back(word.first);
        }

        return res;
    }
};