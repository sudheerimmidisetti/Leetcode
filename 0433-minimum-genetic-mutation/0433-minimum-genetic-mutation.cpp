class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> st(bank.begin(), bank.end());

        if (!st.count(endGene))
            return -1;

        queue<pair<string, int>> q;
        q.push({startGene, 0});

        vector<char> genes = {'A', 'C', 'G', 'T'};

        while (!q.empty()) {
            auto [curr, mutations] = q.front();
            q.pop();

            if (curr == endGene)
                return mutations;

            for (int i = 0; i < 8; i++) {
                char org = curr[i];

                for (auto& c : genes) {
                    curr[i] = c;

                    if (st.count(curr)) {
                        q.push({curr, mutations + 1});
                        st.erase(curr);
                    }
                }

                curr[i] = org;
            }
        }

        return -1;
    }
};