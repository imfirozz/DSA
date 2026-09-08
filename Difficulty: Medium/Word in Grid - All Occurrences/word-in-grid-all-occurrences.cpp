
class Solution {
  public:
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {

        vector<vector<int>> ans;

        int n = mat.size();
        int m = mat[0].size();

        // 8 directions
        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // Starting character must match
                if(mat[i][j] != word[0])
                    continue;

                // Try all 8 directions
                for(int d = 0; d < 8; d++) {

                    int r = i;
                    int c = j;
                    int k = 0;

                    while(k < word.size()) {

                        // Outside grid
                        if(r < 0 || r >= n || c < 0 || c >= m)
                            break;

                        // Character doesn't match
                        if(mat[r][c] != word[k])
                            break;

                        // Move in the same direction
                        r += dr[d];
                        c += dc[d];
                        k++;
                    }

                    // Whole word found
                    if(k == word.size()) {
                        ans.push_back({i, j});
                        break;
                    }
                }
            }
        }

        return ans;
    }
};