class Solution {
public:
    bool is_prime(int n) {
        if (n < 2)
            return false;

        if (n % 2 == 0)
            return n == 2;

        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    int largestPrime(int n) {
        long long primeSum = 2, maxPrimeVal = 0;
        if (n >= 2)
            maxPrimeVal = 2;

        for (int x = 3; primeSum + x <= n; x++) {
            if (is_prime(x)) {
                primeSum += x;

                if (primeSum <= n && is_prime(primeSum))
                    maxPrimeVal = primeSum;
            }
        }
        return maxPrimeVal;
    }
};