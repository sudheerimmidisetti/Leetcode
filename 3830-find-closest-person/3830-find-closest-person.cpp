class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xTime = abs(x - z), yTime = abs(y - z);

        if (xTime < yTime)
            return 1;
        else if (xTime > yTime)
            return 2;
        else
            return 0;
    }
};