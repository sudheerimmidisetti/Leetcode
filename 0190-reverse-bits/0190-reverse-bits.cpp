class Solution {
public:
    int reverseBits(int n) {
        unsigned int num = 0;
        
        int i = 31;
        while (n > 0 && i >= 0) {
            num = num + ((n & 1) * pow(2, i));
            n >>= 1;
            i--;
        }

        return num;
    }
};