class Solution {
	public:
	
	void sub (vector<int>& arr, int size, int index, vector<vector<int>> &ans, vector<int>&temp)
	{
		if (index == size)
			{
			ans.push_back(temp);
			return;
		}
		
		//   dont add the value into the temp
		sub(arr, size, index + 1, ans, temp);
		//   add the value intp temp
		temp.push_back(arr[index]);
		sub(arr, size, index+1, ans, temp);
		//   free the temp
		temp.pop_back();
		
	}
	vector<vector<int>> subsets(vector<int>& arr) {
		// code here
		vector<vector<int>> ans;
		vector<int>temp;
		
		sub(arr, arr.size(), 0, ans, temp);
		return ans;
	}
};
