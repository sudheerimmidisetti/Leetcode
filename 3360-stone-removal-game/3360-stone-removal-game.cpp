class Solution {
public:
    bool canAliceWin(int n) {
        if (n < 10)
            return false;

        int alice = 10, bob = 9, cnt = 0;
        bool aliceWin = true;
        while (n > 0) {
            if (cnt % 2 == 0 && n > 0) {
                n -= alice;
                alice -= 2;
                aliceWin = true;
                if (n < bob)
                    return true;
            } else {
                n -= bob;
                bob -= 2;
                aliceWin = false;
                if (n < alice)
                    return false;
            }

            cnt++;
        }

        return aliceWin;
    }
};