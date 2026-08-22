class Solution {
	
	public:
	
	void subset(vector<int>& arr, int index, int size, int sum, vector<int>&ans)
	{
		if (index == size)
			{
			 //   push the value 0f sum into the array
			ans.push_back(sum);
			return;
			
		}
// 		add the arr value into the sum and move to next 
		subset(arr, index + 1, size, sum + arr[index], ans);
// 		move next without adding the next value
		subset(arr, index + 1, size, sum, ans);
		
	}
	
	vector<int> subsetSums(vector<int>& arr) {
		// code here
		vector<int>ans;
		subset(arr, 0, arr.size(), 0, ans);
		return ans;
	}
};
