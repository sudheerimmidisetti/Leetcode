class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;

        int depth = 0;
        for (char& c : seq) {
            if (c == '(') {
                depth++;
                res.push_back(depth % 2);
                // cout << depth << " " << res.back() << endl;
            } else {
                res.push_back(depth % 2);
                depth--;
                // cout << depth << " " << res.back() << endl;
            }
        }

        return res;
    }
};