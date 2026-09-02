class Solution {
public:
    long long removeZeros(long long n) {
        string s;
        s+=to_string(n);
        string ans;
       for(char c:s)
       {
        if(c!='0')
        ans.push_back(c);
       }
    //    stoll means lomg lomg string
       return stoll(ans);

    }
};