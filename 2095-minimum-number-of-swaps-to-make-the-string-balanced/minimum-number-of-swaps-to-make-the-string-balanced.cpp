class Solution {
public:
    int minSwaps(string s) {

        stack<char> st;
        int count = 0;

        for(char c : s) {

            if(c == '[') {
                st.push('[');
            }
            else {
                if(!st.empty()) {
                    st.pop();
                }
                else {
                    count++;
                }
            }
        }

        return (count + 1) / 2;
    }
};