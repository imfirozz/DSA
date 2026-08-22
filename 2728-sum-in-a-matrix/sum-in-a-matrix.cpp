class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {

        int row = nums.size();
        int cols = nums[0].size();

        // Sort every row
        for (int i = 0; i < row; i++) {
            sort(nums[i].begin(), nums[i].end());
        }

        int sum = 0;

        // For every column/round
        for (int j = 0; j < cols; j++) {

            int maxx = 0;

            // Find maximum among all rows
            for (int i = 0; i < row; i++) {
                maxx = max(maxx, nums[i][j]);
            }

            sum += maxx;
        }

        return sum;
    }
};