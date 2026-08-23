
class Solution {
public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        if (mat[r][c] == '#') return 0;

        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(m, INF));
        deque<pair<int,int>> dq;
        dist[r][c] = 0;
        dq.push_front({r, c});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // 0‑1 BFS: vertical moves cost 1, horizontal moves cost 0
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dr[dir], ny = y + dc[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (mat[nx][ny] == '#') continue;

                int cost = (dir < 2) ? 1 : 0; // up/down = 1, left/right = 0
                if (dist[nx][ny] > dist[x][y] + cost) {
                    dist[nx][ny] = dist[x][y] + cost;
                    if (cost == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dist[i][j] == INF) continue;

                int delta = i - r;          // down - up
                int total = dist[i][j];
                int up = (total - delta) / 2;
                int down = (total + delta) / 2;

                if (up <= u && down <= d) ans++;
            }
        }
        return ans;
    }
};