class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int min = INT_MAX, max = INT_MIN;
        int freq[101] = {0};

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]] = 1;
            if (nums[i] > max)
                max = nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == max)
                continue;

            if (nums[i] < min)
                min = nums[i];
        }

        vector<int> ans;

        for (int i = min + 1; i < max; i++) {
            if (freq[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};