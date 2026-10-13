class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> arr;

        for (int x : nums) {
            arr.push_back(1LL * x * x);
        }

        sort(arr.begin(), arr.end());

        long long sum = 0;
        int n = arr.size();

        for (int i = 0; i < n / 2; i++) {
            sum -= arr[i];
        }

        for (int i = n / 2; i < n; i++) {
            sum += arr[i];
        }

        return sum;
    }
};