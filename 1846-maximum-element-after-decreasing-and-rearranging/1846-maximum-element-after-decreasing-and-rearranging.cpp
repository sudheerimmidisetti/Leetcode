class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int maxEle = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] >= maxEle + 1)
                maxEle++;
        }
        
        return maxEle;
    }
};