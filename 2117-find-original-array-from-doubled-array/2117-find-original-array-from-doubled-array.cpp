class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 != 0)
            return {};

        sort(changed.begin(), changed.end());
        
        unordered_map<int, int> mp;
        for (int num : changed)
            mp[num]++;

        vector<int> res;
        for (int num : changed) {
            if (mp[num] == 0)
                continue;

            if (mp[num * 2] == 0)
                return {};
            
            res.push_back(num);
            mp[num]--;
            mp[num * 2]--;
        }

        return res;
    }
};