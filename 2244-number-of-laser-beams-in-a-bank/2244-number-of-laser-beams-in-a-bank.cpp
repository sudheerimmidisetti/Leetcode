class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int totalCnt = 0, prevCnt = 0;

        for (auto s : bank) {
            int cnt = 0;
            for (auto c : s) {
                if (c == '1')
                    cnt++;
            }

            if (cnt > 0) {
                totalCnt += (prevCnt * cnt);
                prevCnt = cnt;
            }
        }

        return totalCnt;
    }
};