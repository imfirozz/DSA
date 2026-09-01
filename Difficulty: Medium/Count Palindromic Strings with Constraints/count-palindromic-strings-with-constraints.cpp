

class Solution {
public:
    static const long long MOD = 1000000007;

    int palindromicStrings(int n, int k) {

        long long ans = 0;

        // h = number of pairs
        long long evenWays = 1; // P(k, 0)
        long long oddWays = k;  // k * P(k-1, 0)

        for (int h = 0; 2 * h + 1 <= n && h <= k - 1; h++) {

            // Odd length = 2*h + 1
            ans = (ans + oddWays) % MOD;

            if (2 * h + 2 <= n && h + 1 <= k) {

                // P(k, h+1)
                evenWays = evenWays * (k - h) % MOD;

                ans = (ans + evenWays) % MOD;
            }

            // Prepare oddWays for next h
            // k * P(k-1, h+1)
            if (h + 1 <= k - 1) {
                oddWays = oddWays * (k - 1 - h) % MOD;
            }
        }

        return ans;
    }
};