class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return true;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ans;

        for (int i = 0; i < nums2.size(); i++) {

            // Skip duplicate elements in nums2
            if (i > 0 && nums2[i] == nums2[i - 1])
                continue;

            if (search(nums1, nums2[i]))
                ans.push_back(nums2[i]);
        }

        return ans;
    }
};