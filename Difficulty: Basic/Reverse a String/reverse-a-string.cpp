class Solution {
  public:
  
   void reverse(string &s, int start,int end)
   {
       if(start>=end)
       return ;
       
       swap(s[start], s[end]);
       reverse(s, start+1, end-1);
   }
    string reverseString(string& s) {
        // code here
     reverse(s, 0, s.size()-1);
     return s;
    }
};
