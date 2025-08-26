class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiaSq = 0;
        int maxArea = 0;
        for (const auto& d : dimensions) {
            int l = d[0], w = d[1];
            
            double diaSq = sqrt(l * l + w * w);
            int area = l * w;
            if (diaSq > maxDiaSq) {
                maxDiaSq = diaSq;
                maxArea = area;
            } else if (diaSq == maxDiaSq)
                maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};