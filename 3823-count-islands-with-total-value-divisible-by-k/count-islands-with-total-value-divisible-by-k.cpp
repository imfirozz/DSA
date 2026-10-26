class Solution {
public:
    long long bfs(vector<vector<int>>& g, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        long long value = g[i][j];
        g[i][j] = 0;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            int ci = top.first;
            int cj = top.second;

            for (int m = 0; m < 4; m++) {
                int ni = ci + dx[m];
                int nj = cj + dy[m];
                if (ni < 0 or ni >= g.size() or nj < 0 or nj >= g[0].size())
                    continue;
                if (g[ni][nj] == 0)
                    continue;
                value = value + g[ni][nj];
                q.push({ni, nj});
                g[ni][nj] = 0;
            }
        }
        return value;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0) {
                    long long d = bfs(grid, i, j);
                    if (d % k == 0)
                        count++;
                }
            }
        }
        return count;
    }
};