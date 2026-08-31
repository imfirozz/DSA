
class Solution {
public:
    int minCost(int n, int i, int d, int c) {

        vector<int> dp(n + 1, 0);

        dp[0] = 0;

        if (n >= 1)
            dp[1] = i;

        for (int x = 2; x <= n; x++) {

            // Insert one character
            dp[x] = dp[x - 1] + i;

            if (x % 2 == 0) {
                // Make x/2 and copy-paste
                dp[x] = min(dp[x],
                            dp[x / 2] + c);
            }
            else {
                // Make (x+1)/2, copy to x+1,
                // then delete one character
                dp[x] = min(dp[x],
                            dp[(x + 1) / 2] + c + d);
            }
        }

        return dp[n];
    }
};