class Solution {
public:
    long long countPairs(vector<string>& words) {
        long long pairs = 0;
        unordered_map<string, int> mp;

        for (auto& w : words) {
            string str = "";
            int x = w[0] - 'a';

            for (char ch : w) {
                int y = ch - 'a';
                int val = (y - x + 26) % 26;
                str.push_back('a' + val);
            }

            pairs += mp[str];
            mp[str]++;
        }

        return pairs;
    }
};