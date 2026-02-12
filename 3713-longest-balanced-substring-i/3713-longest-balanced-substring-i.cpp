class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();

        int longestSubString = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;

            for (int j = i; j < n; j++) {
                mp[s[j]]++;

                int mini = INT_MAX, maxi = 0;
                for (auto& x : mp) {
                    mini = min(mini, x.second);
                    maxi = max(maxi, x.second);
                }

                if (mini == maxi)
                    longestSubString = max(longestSubString, j - i + 1);
            }
        }

        return longestSubString;
    }
};