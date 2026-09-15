class Solution {
	public:
	vector<int> firstNegInt(vector<int>& arr, int k) {
		// code here
		// push k-1 elemnt into stack
		
		queue<int>q;
		vector<int>ans;
		
		for (int i = 0; i<k - 1; i++)
			{
			if (arr[i]<0)
				q.push(i);
			
		}
		
		// now from k-1 to n cheeck for negative and push to queue
		for (int i = k - 1; i<arr.size(); i++)
			{
			if (arr[i]<0)
				q.push(i);
			
			// check for if the queue size more than given window
			
			
			if (!q.empty()&& q.front() <= i - k)
				q.pop();
			
			// check if the queue is empty then push 0 to ans else push the queue front element
			if (q.empty())
				ans.push_back(0);
			
			else
				ans.push_back(arr[q.front()]);
			
		}
		
		return ans;
	}
};
