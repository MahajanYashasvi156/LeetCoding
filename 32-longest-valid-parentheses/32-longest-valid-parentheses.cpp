class Solution
{
public:
    int longestValidParentheses(string A) 
    {
        vector<int> dp(A.size(),0);
    
        int ans = 0;
        for(int i = 1;i<A.size();i++)
        {
            if(A[i]==')' and A[i-1]=='(')
            {
                if(i==1)
                    dp[i] = 2;
                else
                    dp[i] = dp[i-2]+2;
            }

            else if(A[i]==')' and A[i-1]==')')
            {
                if(i-dp[i-1]-1>=0 and A[i-dp[i-1]-1]=='(')
                {
                    if(i-dp[i-1]-2>=0)
                        dp[i] = dp[i-1] + dp[i-dp[i-1]-2]+2;
                    else
                        dp[i] = dp[i-1] +2;
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
        
    }
};

/*
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

*/