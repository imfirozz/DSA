class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int start = 0, end = nums.size() - 1;
        vector<int> ans;

        while (start <= end) {

            if (nums[start] * nums[start] < nums[end] * nums[end]) {
                ans.push_back(nums[end] * nums[end]);
                end--;
            } else {
                ans.push_back(nums[start] * nums[start]);
                start++;
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};