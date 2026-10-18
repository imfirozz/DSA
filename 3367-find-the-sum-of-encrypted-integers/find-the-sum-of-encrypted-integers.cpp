
class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int maxDigit = 0;
            int digits = 0;

            while (x > 0) {
                maxDigit = max(maxDigit, x % 10);
                digits++;
                x /= 10;
            }

            int encrypted = 0;

            for (int j = 0; j < digits; j++) {
                encrypted = encrypted * 10 + maxDigit;
            }

            ans += encrypted;
        }

        return ans;
    }
};
