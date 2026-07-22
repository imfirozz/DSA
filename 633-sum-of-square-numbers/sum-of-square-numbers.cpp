class Solution {
public:
    bool judgeSquareSum(int c) {

        for (long long a = 0; a * a <= c; a++) {

            long long target = c - a * a;

            long long left = 0, right = sqrt(target);

            while (left <= right) {

                long long mid = left + (right - left) / 2;
                long long square = mid * mid;

                if (square == target)
                    return true;
                else if (square < target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return false;
    }
};