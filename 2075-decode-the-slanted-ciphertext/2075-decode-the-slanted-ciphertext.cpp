class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();

        int cols = n / rows;
        vector<vector<char>> grid(rows, vector<char>(cols));

        int k = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                grid[i][j] = encodedText[k++];

        int i = 0, j = 0;
        string s = "";
        while (i < rows && j < cols) {
            int currJ = j;

            while (i < rows && j < cols)
                s += grid[i++][j++];

            if (i >= rows || j >= cols) {
                i = 0;
                j = currJ + 1;
            }
        }

        while (!s.empty() && s.back() == ' ')
            s.pop_back();

        return s;
    }
};