class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = potions.size();
        sort(potions.begin(), potions.end());

        vector<int> res;
        for (auto spell : spells) {
            long long need = (success + spell - 1) / spell;

            int l = 0, h = m - 1, idx = m;
            while (l <= h) {
                int mid = (l + h) / 2;

                if (potions[mid] >= need) {
                    idx = mid;
                    h = mid - 1;
                } else
                    l = mid + 1;
            }

            res.push_back(m - idx);
        }

        return res;
    }
};