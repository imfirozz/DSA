class Solution {
	public:
	vector<string> generateBinary(int n) {
		// code here
		vector<string>ans;
		queue<string>q;
		
		q.push("1");
		
		while (ans.size()<n)
			{
			    string temp = q.front();
			ans.push_back(temp);
			q.pop();
			
			
			q.push(temp+'0');
			q.push(temp+'1');
		}
		
		return ans;
	}
};
