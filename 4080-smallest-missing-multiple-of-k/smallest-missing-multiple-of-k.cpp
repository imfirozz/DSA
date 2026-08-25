class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        vector<int> ans;

        for (int x : nums) {
            if (x % k == 0) {
                ans.push_back(x);
            }
        }

        sort(ans.begin(), ans.end());
    //   remove duplicates 
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
        // k itself is missing
        if (ans.empty() || ans[0] != k)
            return k;

        // Find the first missing multiple
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i] - ans[i - 1] != k) {
                return ans[i - 1] + k;
            }
        }

        // All multiples found up to the largest one
        return ans.back() + k;
    }
};