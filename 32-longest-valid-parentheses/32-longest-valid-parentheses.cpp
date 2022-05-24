class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int result = 0;
        st.push(-1);
        for(int i =0;i<s.size();i++)
        {
            if(s[i]==')' and st.size()>1 and s[st.top()]=='(')
            {
                st.pop();
                result = max(result,i-st.top()); 
            }
            else
            {
                st.push(i);
            }
        }
        return result;
    }
};