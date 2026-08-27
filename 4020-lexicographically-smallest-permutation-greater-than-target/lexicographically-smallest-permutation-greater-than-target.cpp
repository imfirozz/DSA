
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> total(26, 0);
        for (char ch : s)
            total[ch - 'a']++;

        vector<int> rem = total;
        int last = -1;

        // Find the rightmost position where we can make the string greater
        for (int i = 0; i < n; ++i) {
            int t = target[i] - 'a';

            // Can we place a larger character at position i?
            for (int c = t + 1; c < 26; ++c) {
                if (rem[c] > 0) {
                    last = i;
                    break;
                }
            }

            // Try to keep the prefix equal to target
            if (rem[t] == 0)
                break;
            rem[t]--;
        }

        if (last == -1)
            return "";

        // Reconstruct the answer
        vector<int> counts = total;
        string ans;
        ans.reserve(n);

        // Keep prefix same as target[0..last-1]
        for (int i = 0; i < last; ++i) {
            ans.push_back(target[i]);
            counts[target[i] - 'a']--;
        }

        // Put the smallest possible character > target[last]
        int t = target[last] - 'a';
        for (int c = t + 1; c < 26; ++c) {
            if (counts[c] > 0) {
                ans.push_back(char('a' + c));
                counts[c]--;
                break;
            }
        }

        // Fill remaining suffix with smallest characters possible
        for (int c = 0; c < 26; ++c) {
            while (counts[c] > 0) {
                ans.push_back(char('a' + c));
                counts[c]--;
            }
        }

        return ans;
    }
};