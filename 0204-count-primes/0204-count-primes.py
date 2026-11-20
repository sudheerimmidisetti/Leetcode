class Solution:
    def countPrimes(self, n: int) -> int:
        isPrime = [True] * (n)
        i = 2
        while i * i <= n:
            if isPrime[i]:
                for k in range(i * i, n, i):
                    isPrime[k] = False
            i += 1
        primes = [i for i in range(n) if isPrime[i] == True]

        if n == 0 or n == 1:
            return 0
        else:
            return len(primes) - 2