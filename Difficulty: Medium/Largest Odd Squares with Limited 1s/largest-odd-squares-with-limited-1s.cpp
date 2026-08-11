class Solution {
public:
    vector<int> largestSquare(vector<vector<int>>& mat,
                              vector<vector<int>>& queries,
                              int k) {
        
        int n = mat.size();
        int m = mat[0].size();

        // Prefix sum
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = mat[i - 1][j - 1]
                           + pref[i - 1][j]
                           + pref[i][j - 1]
                           - pref[i - 1][j - 1];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {

            int i = q[0];
            int j = q[1];

            // Maximum possible radius
            int low = 0;
            int high = min({
                i,
                j,
                n - 1 - i,
                m - 1 - j
            });

            int best = -1;

            while (low <= high) {

                int mid = low + (high - low) / 2;

                int r1 = i - mid;
                int c1 = j - mid;
                int r2 = i + mid;
                int c2 = j + mid;

                // Number of 1s in the square
                int ones = pref[r2 + 1][c2 + 1]
                         - pref[r1][c2 + 1]
                         - pref[r2 + 1][c1]
                         + pref[r1][c1];

                if (ones <= k) {
                    // Valid square
                    best = 2 * mid + 1;

                    // Try a bigger square
                    low = mid + 1;
                }
                else {
                    // Too many 1s
                    high = mid - 1;
                }
            }

            ans.push_back(best);
        }

        return ans;
    }
};