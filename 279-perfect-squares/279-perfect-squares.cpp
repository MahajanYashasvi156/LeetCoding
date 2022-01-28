class Solution 
{
public:
    int numSquares(int n) 
    {
        vector<int> dp(n+1);
        dp[0]=0;
      
        int count = 0;
        
        
        for(int i=1;i<=n;i++)
        {
            int mincount = INT_MAX;
            for(int j=1;j*j<=n;j++)
            {
                if(i-j*j>=0)
                    mincount=min(mincount,dp[i-j*j]);
            }
            dp[i]=mincount+1;
        }
        return dp[n];
    }
};