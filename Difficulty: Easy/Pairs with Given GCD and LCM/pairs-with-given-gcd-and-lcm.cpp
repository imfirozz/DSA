
class Solution {
public:
    int pairCount(int x, int y) {

        // LCM must be divisible by GCD
        if(y % x != 0)
            return 0;

        int n = y / x;
        int ans = 0;

        for(int i = 1; i * i <= n; i++) {

            if(n % i == 0) {

                int j = n / i;

                // i and j must be coprime
                if(__gcd(i, j) == 1) {

                    if(i == j)
                        ans += 1;
                    else
                        ans += 2;
                }
            }
        }

        return ans;
    }
};