class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        stack<int>st1;
        stack<int>st2;
        
        // next smallest right 
        vector<int> nsr(arr.size(), arr.size());
        for(int i  = 0; i<arr.size(); i++)
        {
            while(!st1.empty()&& arr[st1.top()]>arr[i])
            {
                nsr[st1.top()] = i;
                st1.pop();
            }
            st1 .push(i);
        }
        
        // next smallest left 
         vector<int> nsl(arr.size(), -1);
         
         for(int i = arr.size()-1  ; i>=0; i--)
         {
             while(!st2.empty()&& arr[st2.top()]>arr[i])
             {
                 nsl[st2.top()] = i;
                 st2.pop();  
             }
             st2.push(i);
         }
         
         vector<int>ans(arr.size(),0);
         
         for(int i = 0; i<arr.size(); i++)
         {
             int len = nsr[i]-nsl[i]-1; 
             
             ans[len-1] = max(ans[len-1], arr[i]);
             
         }
         
         for(int i = arr.size()-2; i>=0; i--)
         {
             ans[i] = max(ans[i], ans[i+1]);
         }
         
         return ans;
    }
};