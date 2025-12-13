class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());

        int score = 0, maxScore = 0;

        int l = 0, r = n - 1;
        while (l <= r) {
            if (power >= tokens[l]) {
                power -= tokens[l];
                score += 1;
                l += 1;
                
                maxScore = max(maxScore, score);
            } else if (score > 0) {
                power += tokens[r];
                score -= 1;
                r -= 1;
            } else
                break;
        }

        return maxScore;
    }
};