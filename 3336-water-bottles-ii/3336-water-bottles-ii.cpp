class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottles = numBottles, bottlesDrunk = numBottles;
        while (numBottles > 0) {
            int fullBottles = 0;
            while (emptyBottles >= numExchange) {
                emptyBottles -= numExchange;
                fullBottles++;
                numExchange++;
            }

            numBottles = fullBottles;
            bottlesDrunk += fullBottles;
            emptyBottles += fullBottles;

            if (emptyBottles < numExchange)
                break;
        }

        return bottlesDrunk;
    }
};