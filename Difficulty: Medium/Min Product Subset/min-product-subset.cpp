
class Solution {
public:
    int minProd(vector<int>& arr) {
        int n = arr.size();
        int neg = 0, zero = 0;
        long long prod = 1;
        long long maxNeg = LLONG_MIN;
        long long minPos = LLONG_MAX;
        for (int x : arr) {
            if (x == 0) zero++;
            else {
                if (x < 0) {
                    neg++;
                    if (x > maxNeg) maxNeg = x;
                } else {
                    if (x < minPos) minPos = x;
                }
                prod *= x;
            }
        }
        if (neg == 0) {
            if (zero > 0) return 0;
            return minPos;
        }
        if (neg % 2 == 1) return prod;
        // even negatives
        long long prodEx = 1;
        bool skipped = false;
        for (int x : arr) {
            if (x == 0) continue;
            if (x < 0 && x == maxNeg && !skipped) {
                skipped = true;
                continue;
            }
            prodEx *= x;
        }
        return prodEx;
    }
};