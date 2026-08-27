
class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> heights(m, 0);
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            // Update the consecutive 1s ending at this row for each column
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1)
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            // Sort the heights in descending order
            vector<int> sortedHeights = heights;
            sort(sortedHeights.rbegin(), sortedHeights.rend());

            // For each possible height, the width is the number of columns
            // with height >= current height
            for (int j = 0; j < m; ++j) {
                int height = sortedHeights[j];
                int width = j + 1;
                ans = max(ans, height * width);
            }
        }

        return ans;
    }
};