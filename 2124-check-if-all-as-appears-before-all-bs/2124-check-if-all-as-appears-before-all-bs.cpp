class Solution {
public:
    bool checkString(string s) {
        int n = s.size();

        int idxA = -1, idxB = n;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                idxA = max(idxA, i);
            else
                idxB = min(idxB, i);
        }
        
        return idxA < idxB;
    }
};