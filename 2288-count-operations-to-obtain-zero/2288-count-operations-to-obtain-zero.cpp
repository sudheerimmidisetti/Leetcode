class Solution {
public:
    int countOperations(int num1, int num2) {
        int minOperations = 0;
        while (num1 > 0 && num2 > 0) {
            minOperations++;

            if (num1 < num2)
                num2 -= num1;
            else if (num1 > num2)
                num1 -= num2;
            else
                break;
        }

        return minOperations;
    }
};