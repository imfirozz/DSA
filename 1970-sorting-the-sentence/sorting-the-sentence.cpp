class Solution {
public:
    string sortSentence(string s) {

        string word = " ";
        vector<string> sequence (10);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '1' && s[i] <= '9') {
                sequence[s[i] - '0'] = word;
                word.clear();

            }

            else {
                word.push_back(s[i]);
            }
        }
            string ans;

            for(int j =1; j<sequence[1].size(); j++)
            {
                ans.push_back(sequence[1][j]);
            }
        for (int i = 2; i < 10; i++) {

            if(sequence[i].size()==0)
            break;

            else
                ans+= sequence[i];
        }

        return ans;
    }
};