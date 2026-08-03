class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        bool freq[256] = {0};
        int ans = 0, start = 0, end = 0;
    //   whole the frequency of the existing elemnt exist then remove it and move start possition
        while(end<s.size())
        {
            while(freq[s[end]])
            {
                freq[s[start]] = 0;
                start++;
            }

            
    //  doest not exist ?  make the count 1 and count the lenth by long - small 
            freq[s[end]] = 1;
            end++;

            ans = max(ans, end-start);

        }
        return ans;
    }
};