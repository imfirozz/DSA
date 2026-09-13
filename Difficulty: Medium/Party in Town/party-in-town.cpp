
class Solution {
public:
    pair<int, int> bfs(int start, vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> dist(n, -1);
        queue<int> q;

        q.push(start);
        dist[start] = 0;

        int farNode = start;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int next : adj[node]) {

                next--;  

                if(dist[next] == -1) {
                    dist[next] = dist[node] + 1;
                    q.push(next);

                    if(dist[next] > dist[farNode])
                        farNode = next;
                }
            }
        }

        return {farNode, dist[farNode]};
    }

    int partyHouse(vector<vector<int>>& adj) {

        pair<int,int> first = bfs(0, adj);

        pair<int,int> second = bfs(first.first, adj);

        int diameter = second.second;

        return (diameter + 1) / 2;
    }
};