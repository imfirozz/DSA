class Solution {
public:
    int maxProduct(vector<int>& arr, int k) {

        sort(arr.begin(), arr.end());

        int n = arr.size();
        int product = 1;

        // Largest is 0 and k is odd
        if(arr[n - 1] == 0 && k % 2 == 1)
            return 0;

        // All elements are <= 0 and k is odd
        if(arr[n - 1] <= 0 && k % 2 == 1) {

            for(int i = n - 1; i >= n - k; i--) {
                product *= arr[i];
            }

            return product;
        }

        int left = 0;
        int right = n - 1;

        // If k is odd, take largest positive
        if(k % 2 == 1) {
            product *= arr[right];
            right--;
            k--;
        }

        // Remaining elements are taken in pairs
        k = k / 2;

        for(int i = 0; i < k; i++) {

            int leftProduct = arr[left] * arr[left + 1];
            int rightProduct = arr[right] * arr[right - 1];

            if(leftProduct > rightProduct) {
                product *= leftProduct;
                left += 2;
            }
            else {
                product *= rightProduct;
                right -= 2;
            }
        }

        return product;
    }
};