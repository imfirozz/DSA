class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       vector<int>sumL; vector<int>sumR;
      int sum= 0;

       for(int i = 0; i<nums.size(); i++)
       {
         sumL.push_back(sum);
         sum+=nums[i];
       }

       sum = 0;
       for(int i = nums.size()-1; i>=0; i--)
       {
        sumR.push_back(sum);
        sum+=nums[i];
       }

       reverse(sumR.begin(), sumR.end());
       for(int i = 0 ; i<nums.size(); i++)
       {
        if(sumL[i]==sumR[i])
        return i;
       }
       return -1;
    
    }
};