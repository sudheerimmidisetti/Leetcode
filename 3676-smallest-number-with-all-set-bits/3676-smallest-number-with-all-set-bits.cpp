class Solution {
public:
    int smallestNumber(int n) {
        while ((floor(log2(n)) + 1) != __builtin_popcount(n)) {
            n++;

            if ((floor(log2(n)) + 1) == __builtin_popcount(n))
                return n;
        }

        return n;
    }
};