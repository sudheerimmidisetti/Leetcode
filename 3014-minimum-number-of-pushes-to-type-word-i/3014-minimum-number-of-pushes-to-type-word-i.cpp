class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        int minClicks = 0, x = 1;
        while (n > 8) {
            minClicks += (x * 8);
            n -= 8;
            x++;
        }

        return minClicks + (x * n);
    }
};