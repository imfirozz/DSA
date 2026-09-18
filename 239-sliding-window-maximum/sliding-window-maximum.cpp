class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // traverse firtst k-1 element
        deque<int> dq;
        for (int i = 0; i < k - 1; i++) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        // trevese k-1 to size

        vector<int> ans;
        for (int i = k - 1; i < nums.size(); i++) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // check for window size if its larger than size of k then remove
            // the front element and push new element

            if (dq.front() <= i - k) {
                dq.pop_front();
            }

            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};