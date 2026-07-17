class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int start = 1;
        int end = nums.size() - 1;
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            int count = 0;

          
            for (int num : nums) {
                if (num <= mid)
                    count++;
            }

            if (count > mid) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};