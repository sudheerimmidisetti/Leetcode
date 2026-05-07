class Solution {
public:
    vector<bool> isPrime;
    vector<int> primes;

    void sieve(int n) {
        isPrime.assign(n + 1, true);

        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }

        for (int i = 2; i <= n; i++) {
            if (isPrime[i] && (n % i) == 0)
                primes.push_back(i);
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        int n = nums.size();

        set<int> st;
        for (auto x : nums) {
            int val = x;
            sieve(x);
            for (int j = 0; j < primes.size(); j++) {
                while ((val % primes[j]) == 0) {
                    val /= primes[j];
                    st.insert(primes[j]);
                }
            }
            primes.clear();
        }

        return st.size();
    }
};