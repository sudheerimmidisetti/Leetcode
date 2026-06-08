class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lesser;
        vector<int> equal;
        vector<int> greater;

        for (auto num : nums) {
            if (num < pivot)
                lesser.push_back(num);
            else if (num > pivot)
                greater.push_back(num);
            else
                equal.push_back(num);
        }

        lesser.insert(lesser.end(), equal.begin(), equal.end());
        lesser.insert(lesser.end(), greater.begin(), greater.end());

        return lesser;
    }
};