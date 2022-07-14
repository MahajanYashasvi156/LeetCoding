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