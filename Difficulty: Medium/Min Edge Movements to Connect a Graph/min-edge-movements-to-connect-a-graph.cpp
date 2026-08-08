class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for (int next : adj[node]) {
            if (!vis[next]) {
                dfs(next, adj, vis);
            }
        }
    }

    int minEdgesReq(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                components++;
                dfs(i, adj, vis);
            }
        }

        // Need components - 1 edges to connect components
        int needed = components - 1;

        // Total edges required to connect n vertices
        if (edges.size() < n - 1)
            return -1;

        return needed;
    }
};