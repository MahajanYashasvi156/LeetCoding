class Solution 
{
    
public:
    int integerBreak(int n) 
    {
        //num(0 to n-1) sum(0 to n)
        vector<int>dp(n+1);
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 1;i<n;i++)
        {
            for(int j = 2;j<=n;j++)
            {
                if(j>=i)
                {
                    dp[j] = max(dp[j],i*dp[j-i]);
                }
            }
        }
        
        return dp[n];
    }
};