class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = needle.size();

        vector<int> lps(n, 0);

        int prefix = 0, suffix = 1;

        while (suffix < n) {
            if (needle[prefix] == needle[suffix]) {
                lps[suffix] = prefix + 1;

                suffix++;
                prefix++;
            }

            else {
                if (prefix == 0) {
                    suffix++;
                }

                else {
                    prefix = lps[prefix - 1];
                }
            }
        }

        prefix = 0, suffix = 0;

        while (prefix < n && suffix < haystack.size()) {
            if (needle[prefix] == haystack[suffix]) {
                prefix++, suffix++;
            }

            else {

                if (prefix == 0) {
                    suffix++;
                }
                else
                prefix = lps[prefix - 1];
            }
        }
        if (prefix == n) {
            return suffix - prefix;
        }

        return -1;
    }
};