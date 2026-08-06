class Solution {
public:
    int countMinOperations(vector<int>& arr) {

        int operations = 0;

        while (true) {

            bool allZero = true;

            for (int x : arr) {
                if (x != 0) {
                    allZero = false;
                    break;
                }
            }

            if (allZero)
                return operations;

            bool hasOdd = false;

            // Remove all odd values
            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] % 2 == 1) {
                    arr[i]--;
                    operations++;
                    hasOdd = true;
                }
            }

            // Divide only if no odd values were present
            if (!hasOdd) {
                for (int i = 0; i < arr.size(); i++)
                    arr[i] /= 2;

                operations++;
            }
        }
    }
};