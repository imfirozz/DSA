class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n  = nums.size();
        vector<int>suffixMax(nums.size());
        int ans = -1;
        suffixMax[n-1] = nums[n-1];
        for(int i = nums.size()-2; i>-1; i--)
        {
            suffixMax[i] = max(nums[i], suffixMax[i+1]);
        }
      
      for(int i = 0; i<nums.size()-1; i++)
      {
         if(suffixMax[i+1]>nums[i])
         {
            ans = max(suffixMax[i+1] -nums[i], ans);
         }
      }
    return ans;
    }
};