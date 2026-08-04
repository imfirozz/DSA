class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int count =0;
       int first   = 0, end = 1;
       
       while(end<arr.size())
       {
           if(arr[end]-arr[first]<k)
           {
               count += end-first;
               end++;
               
           }
           
         else
         first++;
           
           
       }
       return count;
    }
};