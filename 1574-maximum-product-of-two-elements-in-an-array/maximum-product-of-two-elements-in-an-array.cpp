class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int max = nums[nums.size()-1];
        int max2  = nums[nums.size()-2];

        return (max-1)*(max2-1);
    }
};