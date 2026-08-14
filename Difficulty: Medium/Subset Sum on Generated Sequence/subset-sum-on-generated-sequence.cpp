


class Solution {
public:
    bool isPossible(vector<int>& arr, int s, int x) {
        long long sum = s;
        vector<long long> nums;
        nums.push_back(sum);  

   
        for (int i = 0; i < arr.size(); i++) {
            long long current = sum + arr[i];

            
            if (current > x && arr[i] >= 0) break;

            nums.push_back(current);
            sum += current;
        }


        unordered_set<long long> possible;
        possible.insert(0);

        for (long long num : nums) {
            unordered_set<long long> newSums;
            for (long long p : possible) {
                long long val = p + num;
                if (val <= x) {
                    newSums.insert(val);
                }
            }
            possible.insert(newSums.begin(), newSums.end());

            // Early exit if we already found x
            if (possible.find(x) != possible.end()) return true;
        }

        return false;
    }
};