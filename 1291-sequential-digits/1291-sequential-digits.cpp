class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string d = "123456789";

        vector<int> res;
        for (int l = 2; l <= 9; l++) {
            for (int st = 0; st + l <= 9; st++) {
                int x = stoi(d.substr(st, l));

                if (x >= low && x <= high)
                    res.push_back(x);
            }
        }

        return res;
    }
};