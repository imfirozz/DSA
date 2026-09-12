class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        int left = 0, right = 0;
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i]=='(')
            left++;
            
            else
          {
              if(left)
              left--;
              
              else
              right++;
          }
            
        }
        
        return left+right;
    }
};