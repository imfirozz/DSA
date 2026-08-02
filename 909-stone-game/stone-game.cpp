class Solution {
public:
    bool stoneGame(vector<int>& nums) {

           int first = 0;
     int second = 0;
        for(int i =0; i<nums.size(); i = i+2)
        {
          first+= nums[i];
        }
         for(int i =nums.size()-2; i>0; i = i-2)
         {
            second+=nums[i];
         }
       cout<<second<<" "<<first;
       if(first>=second)
       return true;

       else
       return 0;
        
    }
};




  
        
