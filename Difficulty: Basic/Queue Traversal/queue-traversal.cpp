class Solution {
	public:
	vector<int> queueTraversal(queue<int>& q) {
		// code here
		stack<int>st;
		
		while (!q.empty())
			{
			st.push(q.front());
			q.pop();
		}
		
		while (!st.empty())
			{
			q.push(st.top());
			st.pop();
			
		}
		vector<int>ans;
		while (!q.empty())
			{
			ans.push_back(q.front());
			q.pop();
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
