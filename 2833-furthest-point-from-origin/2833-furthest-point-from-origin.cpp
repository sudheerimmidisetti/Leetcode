class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0, r = 0, x = 0;
        for (auto c : moves) {
            if (c == 'L')
                l++;
            else if (c == 'R')
                r++;
            else
                x++;
        }

        return abs(l - r) + x;
    }
};