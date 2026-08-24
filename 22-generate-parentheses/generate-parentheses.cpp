class Solution {
public:

   void genrate(int open, int close,string &temp, vector<string>&ans)
   {
    if(open>close|| open<0)
    return;

    if(open ==0&& close==0)
    {
        ans.push_back(temp);
        return;
    }

    // push "("
    temp.push_back('(');
    genrate(open-1, close, temp,ans);
    temp.pop_back();
    // push ')'
    temp.push_back(')');
    genrate(open, close-1, temp, ans);
    temp.pop_back();
   }
    vector<string> generateParenthesis(int n) {

        vector<string>ans;
        string temp;
        genrate(n,n,temp,ans);
        return ans;
        
    }
};