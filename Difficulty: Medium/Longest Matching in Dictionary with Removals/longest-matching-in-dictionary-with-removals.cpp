
class Solution {
public:

    string findLongestWord(string s, vector<string>& d) {
        int n = s.size();

        // nextPos[i][c] = next position of character c from index i
        vector<vector<int>> nextPos(n + 1, vector<int>(26, -1));

        for(int c = 0; c < 26; c++)
            nextPos[n][c] = -1;

        for(int i = n - 1; i >= 0; i--) {

            nextPos[i] = nextPos[i + 1];

            nextPos[i][s[i] - 'a'] = i;
        }

        string ans = "";

        for(string& word : d) {

            int pos = 0;
            bool possible = true;

            for(char c : word) {

                if(pos > n || nextPos[pos][c - 'a'] == -1) {
                    possible = false;
                    break;
                }

                pos = nextPos[pos][c - 'a'] + 1;
            }

            if(possible) {

                if(word.size() > ans.size() ||
                  (word.size() == ans.size() && word < ans)) {

                    ans = word;
                }
            }
        }

        return ans;
    }
};