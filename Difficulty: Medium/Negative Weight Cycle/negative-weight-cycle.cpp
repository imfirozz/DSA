
class Solution {
public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {

        vector<int> dist(V, 0);

        for (int i = 0; i < V; i++) {

            bool updated = false;

            for (auto &e : edges) {

                int u = e[0];
                int v = e[1];
                int w = e[2];

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    updated = true;

                    // Update on V-th iteration
                    // => negative weight cycle
                    if (i == V - 1)
                        return true;
                }
            }

            // Nothing changed, so no negative cycle
            if (!updated)
                return false;
        }

        return false;
    }
};