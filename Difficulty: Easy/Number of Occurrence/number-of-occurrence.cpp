
class Solution {
public:
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();

        int start = 0, end = n - 1;
        int first = -1, last = -1;

        // Find first occurrence
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] >= target) {
                if (arr[mid] == target)
                    first = mid;

                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        // Target doesn't exist
        if (first == -1)
            return 0;

        start = 0;
        end = n - 1;

        // Find last occurrence
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] <= target) {
                if (arr[mid] == target)
                    last = mid;

                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return last - first + 1;
    }
};