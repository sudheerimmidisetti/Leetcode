class Solution {
public:
    int myAtoi(string s) {
        istringstream   iss(s);
        int num = 0;
        iss >> num;
        return num;
    }
};