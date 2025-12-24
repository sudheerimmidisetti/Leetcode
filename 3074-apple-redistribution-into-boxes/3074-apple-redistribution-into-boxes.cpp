class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = capacity.size();

        int applesCnt = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.rbegin(), capacity.rend());

        int boxesCnt = 0;
        for (int i = 0; i < n; i++) {
            if (applesCnt > 0) {
                applesCnt -= capacity[i];
                boxesCnt++;
            } else
                break;
        }

        return boxesCnt;
    }
};