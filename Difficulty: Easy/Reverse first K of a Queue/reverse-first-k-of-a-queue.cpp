class Solution {
	public:
	queue<int> reverseFirstK(queue<int> q, int k) {
		// code here
		stack<int>st;
		vector<int>ans;
		
		
		if(k>q.size())
		return q;
		while (k)
			{
			st.push(q.front());
			q.pop();
			k--;
		}
		
		int size = q.size();
		while (!st.empty())
			{
			q.push(st.top());
			st.pop();
		}
		
		// 		push the remaining element 0f queue into stack and then. into queue
		
		for (int i = 0; i<size; i++)
			{
			q.push(q.front());
			q.pop();
		}
// 	
		
		return q;
	}
};
