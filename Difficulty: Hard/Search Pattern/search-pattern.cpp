class Solution {
	public:
	vector<int> search(string &pat, string &txt) {
		// code here
		
		int n = pat.size();
		vector<int>ans;
		vector<int> lps(n, 0);
		
		int prefix = 0, suffix = 1;
		
		while (suffix < n) {
			if (pat[prefix] == pat[suffix]) {
				lps[suffix] = prefix + 1;
				
				suffix++;
				prefix++;
			}
			
			else {
				if (prefix == 0) {
					suffix++;
				}
				
				else {
					prefix = lps[prefix - 1];
				}
			}
		}
		
		prefix = 0, suffix = 0;
		
		while (prefix < n && suffix < txt.size()) {
			if (pat[prefix] == txt[suffix]) {
				prefix++;
				suffix++;
				
				if (prefix == n) {
					ans.push_back(suffix - prefix);
					prefix = lps[prefix - 1];
				}
			}
			
			else {
				
				if (prefix == 0) {
					suffix++;
				}
				else
					prefix = lps[prefix - 1];
			}
		}
		
		return ans;
		
	}
};
