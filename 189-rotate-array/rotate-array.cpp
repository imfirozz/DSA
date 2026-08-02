class Solution {
public:
    void rotate(vector<int>& arr, int j) {

        int k = j%arr.size();

        reverse(arr.begin(), arr.end());

        int start = 0, end = k - 1;
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }

        start = k, end = arr.size() - 1;

        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
};