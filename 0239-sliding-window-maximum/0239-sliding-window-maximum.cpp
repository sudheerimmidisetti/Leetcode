class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> res;
        int maxi = INT_MIN, i = 0;

        deque<int> dq;
        for (int j = 0; j < n; j++) {
            while (!dq.empty() && dq.back() < nums[j])
                dq.pop_back();

            dq.push_back(nums[j]);

            if (j - i + 1 == k) {
                res.push_back(dq.front());

                if (dq.front() == nums[i])
                    dq.pop_front();

                i++;
            }
        }

        return res;
    }
};