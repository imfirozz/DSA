class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int index,
               int size) {
        if (index == size - 1) {
            // nums becouse the nums is already swaped or manupulated
            // we didnt include nums[i] becouse we need whole array here array is contain large set of data if we do [i] then only one valude we be added
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < size; i++) {

            swap(nums[index], nums[i]);
            // swap to get each element of array to be at the first index
            solve(nums, ans, index + 1, size);
            // call the function so it solve the next
            swap(nums[index], nums[i]);
            //  since the aray is passed by refrense the araay is modifed so we
            //  need to get it back to orginal shape so that other can use un
            //  manupilated aaray
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        solve(nums, ans, 0, nums.size());
        return ans;
    }
};