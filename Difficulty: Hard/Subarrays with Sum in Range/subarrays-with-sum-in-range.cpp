class Solution {
    long long merge(vector<long long>& pre, int left, int mid, int right,
                    int l, int r) {

        long long cnt = 0;

        int low = mid;
        int high = mid;

        for (int i = left; i < mid; i++) {

            while (low < right && pre[low] - pre[i] < l)
                low++;

            while (high < right && pre[high] - pre[i] <= r)
                high++;

            cnt += (high - low);
        }

        vector<long long> temp;
        int i = left, j = mid;

        while (i < mid && j < right) {
            if (pre[i] <= pre[j])
                temp.push_back(pre[i++]);
            else
                temp.push_back(pre[j++]);
        }

        while (i < mid)
            temp.push_back(pre[i++]);

        while (j < right)
            temp.push_back(pre[j++]);

        for (int k = left; k < right; k++)
            pre[k] = temp[k - left];

        return cnt;
    }

    long long mergeSort(vector<long long>& pre, int left, int right,
                        int l, int r) {

        if (right - left <= 1)
            return 0;

        int mid = (left + right) / 2;

        long long cnt = 0;

        cnt += mergeSort(pre, left, mid, l, r);
        cnt += mergeSort(pre, mid, right, l, r);
        cnt += merge(pre, left, mid, right, l, r);

        return cnt;
    }

public:
    int countSubarray(vector<int>& arr, int l, int r) {

        int n = arr.size();

        vector<long long> pre(n + 1, 0);

        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + arr[i];

        return (int)mergeSort(pre, 0, n + 1, l, r);
    }
};