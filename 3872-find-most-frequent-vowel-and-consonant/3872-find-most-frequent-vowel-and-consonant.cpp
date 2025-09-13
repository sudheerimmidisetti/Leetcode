class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> mp;
        for (auto ch : s) {
            mp[ch]++;
        }

        int maxVol = 0, maxCon = 0;
        for (auto freq : mp) {
            if (freq.first == 'a' || freq.first == 'e' || freq.first == 'i' ||
                freq.first == 'o' || freq.first == 'u') {
                maxVol = max(maxVol, freq.second);
            } else {
                maxCon = max(maxCon, freq.second);
            }
        }

        return maxVol + maxCon;
    }
};