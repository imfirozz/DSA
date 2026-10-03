class Solution {
public:
    string makeFancyString(string s) {

        string ans = "";

        int count = 0;
        char prev = '#';

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == prev)
                count++;
            else {
                prev = s[i];
                count = 1;
            }

            if(count < 3)
                ans += s[i];
        }

        return ans;
    }
};