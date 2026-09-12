class Solution {
  public:
    stack<int> insertAtBottom(stack<int> &st, int x) {
        // code here
        stack<int>s1;
       
        while(!st.empty())
        {
            s1.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!s1.empty())
        {
            st.push(s1.top());
            s1.pop();
        }
        return st;
    }
};