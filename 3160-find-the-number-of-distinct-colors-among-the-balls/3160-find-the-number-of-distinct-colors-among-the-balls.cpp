class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballsColor, colorsCnt;

        vector<int> res;
        for (auto &q : queries) {
            if (ballsColor.count(q[0])) {
                colorsCnt[ballsColor[q[0]]]--;

                if (colorsCnt[ballsColor[q[0]]] == 0)
                    colorsCnt.erase(ballsColor[q[0]]);
            }

            ballsColor[q[0]] = q[1];
            colorsCnt[q[1]]++;

            res.push_back(colorsCnt.size());
        }

        return res;
    }
};