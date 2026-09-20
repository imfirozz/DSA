
class Solution {
public:
    int largestSubsquare(vector<vector<char>>& mat) {
        int n = mat.size();

        vector<vector<int>> right(n, vector<int>(n, 0));
        vector<vector<int>> down(n, vector<int>(n, 0));

        // Precompute right and down X's
        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {

                if(mat[i][j] == 'X') {
                    right[i][j] = 1;
                    down[i][j] = 1;

                    if(j + 1 < n)
                        right[i][j] += right[i][j + 1];

                    if(i + 1 < n)
                        down[i][j] += down[i + 1][j];
                }
            }
        }

        int ans = 0;

        // Try every top-left corner
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                // Try every possible side length
                for(int len = 1; i + len <= n && j + len <= n; len++) {

                    int bottom = i + len - 1;
                    int rightCol = j + len - 1;

                    if(right[i][j] >= len &&
                       down[i][j] >= len &&
                       right[bottom][j] >= len &&
                       down[i][rightCol] >= len) {

                        ans = max(ans, len);
                    }
                }
            }
        }

        return ans;
    }
};