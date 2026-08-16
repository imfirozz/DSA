class Solution {
	public:
	
	bool pali(string &s, int end, int start)
	{
		if (start >= end)
			return 1;
		if (s[end] != s[start])
			return 0;
		return pali(s, end - 1, start + 1);
	}
	bool isPalindrome(string& s) {
		// code here
		return pali(s, s.size() - 1, 0);
	}
};
