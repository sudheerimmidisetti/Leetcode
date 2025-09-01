class Solution {
public:
    double gain(int pass, int total) {
        return ((double)(pass + 1) / (total + 1)) - ((double)pass / total);
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for (int i = 0; i < n; i++) {
            maxHeap.push({gain(classes[i][0], classes[i][1]),
                          {classes[i][0], classes[i][1]}});
        }

        while (extraStudents--) {
            auto [g, c] = maxHeap.top();
            maxHeap.pop();

            int pass = c.first, totalStudentsCnt = c.second;
            pass++, totalStudentsCnt++;

            maxHeap.push(
                {gain(pass, totalStudentsCnt), {pass, totalStudentsCnt}});
        }

        double totalPassRatio = 0;
        while (!maxHeap.empty()) {
            auto [g, c] = maxHeap.top();
            maxHeap.pop();

            totalPassRatio += (double)c.first / c.second;
        }

        return totalPassRatio / n;
    }
};