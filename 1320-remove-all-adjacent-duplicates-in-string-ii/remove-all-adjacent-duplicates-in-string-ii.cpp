class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> st;
        int freq = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (st.empty()) {
                st.push(s[i]);
                freq = 1;
            }
            else if (st.top() == s[i]) {
                st.push(s[i]);
                freq++;
            }
            else {
                st.push(s[i]);
                freq = 1;
            }

            ans = freq;

            if (ans == k) {
                while (ans > 0) {
                    st.pop();
                    ans--;
                }

                freq = 0;

             
                if (!st.empty()) {
                    char ch = st.top();
                    stack<char> temp = st;

                    while (!temp.empty() && temp.top() == ch) {
                        freq++;
                        temp.pop();
                    }
                }
            }
        }

        string result = "";

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};