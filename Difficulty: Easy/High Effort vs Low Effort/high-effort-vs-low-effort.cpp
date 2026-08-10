class Solution {
  public:
    int maxTask(vector<int>& hi, vector<int>& li) {
        // code here
        int n = hi.size();
         vector<int> dp(n + 1, 0);

        dp[1] = max(hi[0], li[0]);

        for (int i = 2; i <= n; i++) {

            dp[i] = max(
                dp[i - 1] + li[i - 1],
                dp[i - 2] + hi[i - 1]
            );
        }

        return dp[n];
    }
    
};