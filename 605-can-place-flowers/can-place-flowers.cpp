class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        int size = arr.size();

        for (int i = 0; i < size && n > 0; i++) {

            if (arr[i] == 0) {

                bool leftEmpty = (i == 0 || arr[i - 1] == 0);
                bool rightEmpty = (i == size - 1 || arr[i + 1] == 0);

                if (leftEmpty && rightEmpty) {
                    arr[i] = 1;
                    n--;
                }
            }
        }

        return n == 0;
    }
};