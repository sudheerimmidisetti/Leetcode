int hammingWeight(int n) {
    long long c = 0, bin[32], i = 0;
    while (n > 0) {
        bin[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        if (bin[j] == 1)
            c++;
    }
    return c;
}