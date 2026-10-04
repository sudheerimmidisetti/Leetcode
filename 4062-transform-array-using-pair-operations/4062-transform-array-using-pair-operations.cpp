class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        return accumulate(source.begin(), source.end(), 0ll) ==
               accumulate(target.begin(), target.end(), 0ll);
    }
};