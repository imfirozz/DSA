class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int first = 0, last = 0;
        string ans = "";

        while(first < word1.size() || last < word2.size()) {

            if(first < word1.size()) {
                ans += word1[first];
                first++;
            }

            if(last < word2.size()) {
                ans += word2[last];
                last++;
            }
        }

        return ans;
    }
};