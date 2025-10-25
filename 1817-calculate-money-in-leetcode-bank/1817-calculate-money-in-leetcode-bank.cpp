class Solution {
public:
    int totalMoney(int n) {
        int money = 0;
        int week = 0;

        while (n > 0) {
            for (int day = 1; day <= 7 && n > 0; day++) {
                money += week + day;
                n--;
            }
            
            week++;
        }

        return money;
    }
};