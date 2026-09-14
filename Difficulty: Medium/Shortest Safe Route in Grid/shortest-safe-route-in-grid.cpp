
class Solution {
public:

    int shortestPath(vector<vector<int>> &mat) {

        int n = mat.size();
        int m = mat[0].size();

        // Step 1: Mark cells adjacent to landmines as unsafe
        vector<vector<int>> safe = mat;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(mat[i][j] == 0) {

                    for(int d = 0; d < 4; d++) {

                        int r = i + dr[d];
                        int c = j + dc[d];

                        if(r >= 0 && r < n && c >= 0 && c < m)
                            safe[r][c] = 0;
                    }
                }
            }
        }

        // Step 2: BFS
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Start from every safe cell in leftmost column
        for(int i = 0; i < n; i++) {

            if(safe[i][0] == 1) {
                q.push({{i, 0}, 1});
                visited[i][0] = 1;
            }
        }

        while(!q.empty()) {

            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;

            q.pop();

            // Reached rightmost column
            if(c == m - 1)
                return dist;

            for(int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   safe[nr][nc] == 1 &&
                   !visited[nr][nc]) {

                    visited[nr][nc] = 1;
                    q.push({{nr, nc}, dist + 1});
                }
            }
        }

        return -1;
    }
};