class Solution {
public:
    int countTriplets(vector<int> &arr, int l, int r) {
        // Sort a copy for two-pointer counting
        vector<int> a = arr;
        sort(a.begin(), a.end());

        // Count triplets with sum <= X
        auto countAtMost = [&](int X) -> long long {
            int n = a.size();
            if (n < 3) return 0;
            long long ans = 0;
            for (int i = 0; i < n - 2; i++) {
                int target = X - a[i];
                int j = i + 1, k = n - 1;
                while (j < k) {
                    if (a[j] + a[k] <= target) {
                        ans += (k - j);
                        j++;
                    } else {
                        k--;
                    }
                }
            }
            return ans;
        };

        long long high = countAtMost(r);
        long long low  = countAtMost(l - 1);
        return (int)(high - low);
    }
};