class Solution {
public:
    vector<int> findWays(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int MOD = 1000000007;

        vector<vector<long long>> ways(
            n, vector<long long>(n, 0)
        );

        vector<vector<long long>> adventure(
            n, vector<long long>(n, 0)
        );

        ways[0][0] = 1;
        adventure[0][0] = matrix[0][0];

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                // Come from TOP
                if (i > 0 &&
                    (matrix[i - 1][j] == 2 ||
                     matrix[i - 1][j] == 3)) {

                    ways[i][j] =
                        (ways[i][j] + ways[i - 1][j]) % MOD;

                    if (ways[i - 1][j] > 0) {
                        adventure[i][j] =
                            max(adventure[i][j],
                                adventure[i - 1][j] + matrix[i][j]);
                    }
                }

                // Come from LEFT
                if (j > 0 &&
                    (matrix[i][j - 1] == 1 ||
                     matrix[i][j - 1] == 3)) {

                    ways[i][j] =
                        (ways[i][j] + ways[i][j - 1]) % MOD;

                    if (ways[i][j - 1] > 0) {
                        adventure[i][j] =
                            max(adventure[i][j],
                                adventure[i][j - 1] + matrix[i][j]);
                    }
                }
            }
        }

        return {
            (int)ways[n - 1][n - 1],
            (int)adventure[n - 1][n - 1]
        };
    }
};