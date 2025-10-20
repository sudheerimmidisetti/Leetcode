class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (auto& ops : operations) {
            if (ops == "X++" || ops == "++X")
                x++;
            else
                x--;
        }

        return x;
    }
};