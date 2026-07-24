class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans(nums.size());
        int i = ans.size()-1;

        int start = 0, end = nums.size()-1;
        while(start<=end)
        {
            if(nums[start]*nums[start]<nums[end]*nums[end])
           { ans[i--] = nums[end]*nums[end];
            end--;}

            else 
            {
                ans[i--] = nums[start]*nums[start];
                start++;
            }
        }

        return ans;
    }
};