
class Solution {
public:
    int dominantPairs(vector<int>& arr) {
        int n = arr.size();
        int half = n / 2;

        sort(arr.begin(), arr.begin() + half);
        sort(arr.begin() + half, arr.end());

        int i = 0;
        int count = 0;

        for(int j = half; j < n; j++) {

            while(i < half && arr[i] < 5 * arr[j]) {
                i++;
            }

            count += half - i;
        }

        return count;
    }
};