class Solution {
	public:
	int minThrows(int n, vector<int>& lad, vector<int>& sn) {
		// code here
		
		int totalCells = n * n;
		vector<int> board(totalCells + 1, -1);
		
		// Mark ladders
		for (int i = 0; i < lad.size(); i += 2) {
			board[lad[i]] = lad[i + 1];
		}
		
		// Mark snakes
		for (int i = 0; i < sn.size(); i += 2) {
			board[sn[i]] = sn[i + 1];
		}
		
		// BFS
		vector<bool> visited(totalCells + 1, false);
		queue<pair<int, int>> q; // {cell, moves}
		
		q.push({1, 0});
		visited[1] = true;
		
		while (!q.empty()) {
			auto [curr, moves] = q.front();
			q.pop();
			
			if (curr == totalCells)
				return moves;
			
			// Try all dice outcomes (1 to 6)
			for (int dice = 1; dice <= 6; dice++) {
				int next = curr + dice;
				if (next > totalCells)
					continue;
				
				// If there's a snake/ladder
				if (board[next] != -1)
					next = board[next];
				
				if (!visited[next]) {
					visited[next] = true;
					q.push({next, moves + 1});
				}
			}
		}
		
		return - 1; // Impossible to reach
	}
};
