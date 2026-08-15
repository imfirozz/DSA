
class Solution {
public:
    long long countWithout(long long n, int d) {
        if (n <= 0) return 0;

        string s = to_string(n);
        int len = s.size();
        long long ans = 0;

        // Precompute powers of 9 up to len
        vector<long long> pow9(len, 1);
        for (int i = 1; i < len; i++) {
            pow9[i] = pow9[i - 1] * 9;
        }

        // Count numbers with fewer digits
        int firstDigitChoices = (d == 0) ? 9 : 8;   // first digit cannot be 0 and cannot be d
        for (int i = 1; i < len; i++) {
            ans += firstDigitChoices * pow9[i - 1];
        }

        // Count numbers with same number of digits
        for (int i = 0; i < len; i++) {
            int cur = s[i] - '0';
            int smaller = 0;

            // Count allowed digits less than cur at this position
            for (int digit = 0; digit < cur; digit++) {
                if (i == 0 && digit == 0) continue; // no leading zero
                if (digit == d) continue;
                smaller++;
            }

            int remaining = len - i - 1;
            ans += smaller * pow9[remaining];

            // If current digit is forbidden, cannot continue with this prefix
            if (cur == d) return ans;
        }

        // n itself is valid
        return ans + 1;
    }
};