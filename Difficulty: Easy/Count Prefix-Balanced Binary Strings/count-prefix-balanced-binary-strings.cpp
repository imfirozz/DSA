
class Solution {
public:
    int prefixStrings(int n) {
        const long long MOD = 1000000007;

        auto modpow = [](long long a, long long e) {
            long long res = 1;
            while (e > 0) {
                if (e & 1) res = (res * a) % MOD;
                a = (a * a) % MOD;
                e >>= 1;
            }
            return res;
        };

        long long numerator = 1; // product of (n+1) to (2n)
        long long denominator = 1; // n!

        for (long long i = 1; i <= n; ++i) {
            numerator = (numerator * (n + i)) % MOD;
            denominator = (denominator * i) % MOD;
        }

        // C(2n, n) = numerator / denominator
        long long comb = numerator * modpow(denominator, MOD - 2) % MOD;

        // Catalan number = C(2n, n) / (n + 1)
        long long ans = comb * modpow(n + 1, MOD - 2) % MOD;

        return (int)ans;
    }
};