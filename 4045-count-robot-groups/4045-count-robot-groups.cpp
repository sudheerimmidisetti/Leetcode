class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();

        vector<int> grps;
        for (int i = 0; i < n;) {
            int j = i;
            while ((j + 1) < n && (position[j + 1] - position[j]) <= distance)
                j++;

            grps.push_back(j);
            i = j + 1;
        }

        int cnt = 0, sz = grps.size(), r = grps.back();
        for (int i = sz - 2; i >= 0; i--) {
            int l = grps[i];

            if (speed[l] > speed[r])
                continue;

            cnt++;
            r = l;
        }

        return cnt + 1;
    }
};