class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end(), [&](int a, int b) {
            int sumA = digitSum(a);
            int sumB = digitSum(b);

            if (sumA != sumB)
                return sumA < sumB;
            return a < b;
        });

        unordered_map<int, int> idxs;
        for (int i = 0; i < n; i++)
            idxs[nums[i]] = i;

        int swapsCnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == sorted[i])
                continue;

            int j = idxs[sorted[i]];

            idxs[nums[i]] = j;
            idxs[sorted[i]] = i;

            swap(nums[i], nums[j]);
            swapsCnt++;
        }

        return swapsCnt;
    }
};