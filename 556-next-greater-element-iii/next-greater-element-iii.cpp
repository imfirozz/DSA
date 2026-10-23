
class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> ans;

        while (n > 0) {
            ans.push_back(n % 10);
            n /= 10;
        }

        reverse(ans.begin(), ans.end());

        int i = ans.size() - 2;

        // Find the first digit that can be increased
        while (i >= 0 && ans[i] >= ans[i + 1]) {
            i--;
        }

        if (i < 0) return -1;

        // Find the smallest digit greater than ans[i]
        int j = ans.size() - 1;

        while (ans[j] <= ans[i]) {
            j--;
        }

        swap(ans[i], ans[j]);

        // Make the remaining suffix as small as possible
        reverse(ans.begin() + i + 1, ans.end());

        long long solve = 0;

        for (int digit : ans) {
            solve = solve * 10 + digit;
        }

        if (solve > INT_MAX) return -1;

        return (int)solve;
    }
};
