class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > (9 * num))
            return "";
        
        string res = "";
        for (int i = 0; i < num; i++) {
            res.push_back('0' + min(9, sum));
            sum -= min(9, sum);
        }

        if (sum != 0)
            return "";
        
        return res;
    }
};