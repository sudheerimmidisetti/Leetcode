class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string s1 = to_string(nums[i]), s2 = to_string(nums[j]);

                int n1 = s1.length(), n2 = s2.length(), maxLen = max(n1, n2);
                while (n1 != maxLen) {
                    s1 = "0" + s1;
                    n1++;
                }

                while (n2 != maxLen) {
                    s2 = "0" + s2;
                    n2++;
                }

                unordered_map<char, int> mp1, mp2;

                int diff = 0;
                for (int i = 0; i < maxLen; i++) {
                    diff += (s1[i] != s2[i]);

                    mp1[s1[i]]++;
                    mp2[s2[i]]++;
                }

                if (diff <= 2 && mp1 == mp2)
                    cnt++;
            }
        }

        return cnt;
    }
};