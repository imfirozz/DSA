
class Solution {
public:
    int findMinCost(string& s1, string& s2, int costS1, int costS2) {

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // LCS
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lcs = dp[n][m];

        // Delete everything except LCS
        int deleteS1 = n - lcs;
        int deleteS2 = m - lcs;

        return deleteS1 * costS1 + deleteS2 * costS2;
    }
};