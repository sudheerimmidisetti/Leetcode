class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int n = s.size();

        unordered_map<char, int> mp;
        for (auto& c : s)
            mp[c]++;

        return abs(mp['a'] - mp['b']);
    }
};