class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse every row
        for (int i = 0; i < n; i++) {

            int colStart = 0;
            int colEnd = n - 1;

            while (colStart < colEnd) {

                swap(matrix[i][colStart], matrix[i][colEnd]);

                colStart++;
                colEnd--;
            }
        }
    }
};