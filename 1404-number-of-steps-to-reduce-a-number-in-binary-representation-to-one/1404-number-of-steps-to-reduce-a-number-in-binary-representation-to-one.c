int numSteps(char* s) {
    int steps = 0, carry = 0, len = strlen(s);

    for (int i = len - 1; i > 0; i--) {
        if (s[i] - '0' + carry == 1) {
            carry = 1;
            steps += 2;
        } else
            steps += 1;
    }
    steps += carry;

    return steps;
}