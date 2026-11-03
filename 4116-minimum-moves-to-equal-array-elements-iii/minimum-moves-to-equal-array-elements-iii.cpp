class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxx = 0;
        for(int i = 0; i<nums.size(); i++)
        {
        maxx = max(maxx,nums[i]);
        }
        int ans = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i]!=maxx)
            {
                ans+=maxx-nums[i];
            }
        }
       return ans;
        
    }
};