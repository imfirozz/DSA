
class Solution {
public:
    int digitSum(int n) {
        int sum = 0;

        while(n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int findMax(int n) {
        int ans = n;
        int maxSum = digitSum(n);

        int x = n;
        int place = 1;

        while(x > 0) {

            int candidate = (x - 1) * place + (place - 1);

            int sum = digitSum(candidate);

            if(sum > maxSum || (sum == maxSum && candidate > ans)) {
                maxSum = sum;
                ans = candidate;
            }

            x /= 10;
            place *= 10;
        }

        return ans;
    }
};