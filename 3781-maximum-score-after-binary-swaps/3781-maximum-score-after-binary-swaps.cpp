class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        int n = nums.size();

        long long maxScore = 0;
        priority_queue<int> pq;

        for (int i = 0; i < n; i++) {
            pq.push(nums[i]);

            if (s[i] == '1') {
                maxScore += pq.top();
                pq.pop();
            }
        }

        return maxScore;
    }
};