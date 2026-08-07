class Solution {
public:
    long long solve(int n, vector<long long>& dp) {

        if (n <= 2)
            return n;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = solve(n - 1, dp) +
                       (n - 1) * solve(n - 2, dp);
    }

    long long countFriendsPairings(int n) {

        vector<long long> dp(n + 1, -1);

        if (n == 1)
            return 1;

        return solve(n, dp);
    }
};