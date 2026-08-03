class Solution {
public:
    long long maxSumWithK(vector<int>& arr, int k) {

        int n = arr.size();

        vector<long long> maxEnd(n);

        maxEnd[0] = arr[0];

        for (int i = 1; i < n; i++)
            maxEnd[i] = max((long long)arr[i],
                            maxEnd[i - 1] + arr[i]);

        long long windowSum = 0;

        for (int i = 0; i < k; i++)
            windowSum += arr[i];

        long long ans = windowSum;

        for (int i = k; i < n; i++) {

            windowSum += arr[i];
            windowSum -= arr[i - k];

            ans = max(ans, windowSum);

            ans = max(ans, windowSum + maxEnd[i - k]);
        }

        return ans;
    }
};