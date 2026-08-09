class Solution {
public:
    int zigzagSequence(vector<vector<int>>& mat) {

        int n = mat.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Last row
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = mat[n - 1][j];
        }

        // Build from bottom to top
        for (int i = n - 2; i >= 0; i--) {

            for (int j = 0; j < n; j++) {

                int best = 0;

                for (int k = 0; k < n; k++) {

                    if (k != j) {
                        best = max(best, dp[i + 1][k]);
                    }
                }

                dp[i][j] = mat[i][j] + best;
            }
        }

        // Best starting point in first row
        int ans = 0;

        for (int j = 0; j < n; j++) {
            ans = max(ans, dp[0][j]);
        }

        return ans;
    }
};