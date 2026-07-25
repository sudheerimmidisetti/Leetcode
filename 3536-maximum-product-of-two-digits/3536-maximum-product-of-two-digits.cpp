class Solution {
public:
    int maxProduct(int n) {
        string num = to_string(n);
        sort(num.begin(), num.end());

        return (int)(num[num.size() - 1] - '0') * (int)(num[num.size() - 2] - '0');
    }
};