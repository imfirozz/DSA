class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        int ans = -1;
        int low = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > low) {
                ans = max(ans,nums[i]-low);

            } else
                low = min(nums[i], low);
        }

        return ans;
    }
};