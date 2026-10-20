class Solution {
public:
    int minimizedStringLength(string s) {
        vector<bool> freq(26, 0);
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a'] = true;
        }
        for (int i = 0; i < freq.size(); i++) {
            if(freq[i]>0)
            count++;
        }
        return count;
    }
};