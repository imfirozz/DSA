class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        // int size = nums.size()+1;
        vector<int>arr1;
        vector<int>arr2;
        arr1.push_back(nums[0]);
        int last =arr1[0];
    
        arr2.push_back(nums[1]);
        int last2 =arr2[0];
     
        // if(nums.size()<=2)
        // return nums;

        for(int i = 2;i<nums.size(); i++)
        {
                if(last>last2)
                {
                    arr1.push_back(nums[i]);
                    last = nums[i];
                }
                else
                {
                    arr2.push_back(nums[i]);
                    last2 = nums[i];
                }

        }
      for(int i = 0; i<arr2.size(); i++)
      {
        arr1.push_back(arr2[i]);
      }
        for(int i = 0; i<arr1.size(); i++)
      {
        cout<<arr1[i]<<" ";
      }
       return arr1;
    }
};