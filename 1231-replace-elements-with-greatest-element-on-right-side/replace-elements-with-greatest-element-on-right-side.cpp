
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans;
        int last = -1;

        reverse(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++) {
            ans.push_back(last);
            last = max(last, arr[i]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
