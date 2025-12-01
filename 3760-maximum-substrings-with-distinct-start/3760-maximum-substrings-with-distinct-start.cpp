class Solution {
public:
    int maxDistinct(string s) {
        return set<char>(s.begin(), s.end()).size();
    }
};