
class Solution {
public:

    int solve(int i, int inc, int dec,
              vector<int>& arr,
              vector<vector<vector<int>>>& dp) {

        // All elements processed
        if (i == arr.size())
            return 0;

        // Already calculated
        if (dp[i][inc + 1][dec + 1] != -1)
            return dp[i][inc + 1][dec + 1];

        // 1. Skip current element
        int ans = 1 + solve(i + 1, inc, dec, arr, dp);

        // 2. Put current element in increasing subsequence
        if (inc == -1 || arr[i] > arr[inc]) {
            ans = min(ans,
                      solve(i + 1, i, dec, arr, dp));
        }

        // 3. Put current element in decreasing subsequence
        if (dec == -1 || arr[i] < arr[dec]) {
            ans = min(ans,
                      solve(i + 1, inc, i, arr, dp));
        }

        return dp[i][inc + 1][dec + 1] = ans;
    }

    int minCount(vector<int>& arr) {
        int n = arr.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(n + 1,
                vector<int>(n + 1, -1)
            )
        );

        return solve(0, -1, -1, arr, dp);
    }
};