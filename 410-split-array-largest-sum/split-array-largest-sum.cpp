class Solution {
public:
    bool split(int mid, vector<int>& nums, int k) {
        int part = 1, LargestSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (LargestSum + nums[i] <= mid) {

                LargestSum += nums[i];

            }

            else {
                part++;
                LargestSum = nums[i];
            }
        }

        return part <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int start = INT_MIN, end = 0;
        for (int i = 0; i < nums.size(); i++) {
            start = max(start, nums[i]);
            end += nums[i];
        }

        int ans;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (split(mid, nums, k)) {
                ans = mid;
                end = mid - 1;
            }

            else
                start = mid + 1;
        }
        return ans;
    }
};