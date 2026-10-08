class Solution {
public:
    int minInsertions(string s) {

        stack<char> st;
        int ans = 0;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(') {
                st.push('(');
            }
            else {

                // We need another ')' after this one
                if(i + 1 < s.size() && s[i + 1] == ')') {

                    if(!st.empty()) {
                        st.pop();
                    }
                    else {
                        // Need an opening '('
                        ans++;
                    }

                    i++;
                }

                else {
                    // Current ')' has no second ')'
                    ans++;

                    if(!st.empty()) {
                        st.pop();
                    }
                    else {
                        // Need '(' before this ')'
                        ans++;
                    }
                }
            }
        }

        // Every remaining '(' needs two ')'
        ans += st.size() * 2;

        return ans;
    }
};