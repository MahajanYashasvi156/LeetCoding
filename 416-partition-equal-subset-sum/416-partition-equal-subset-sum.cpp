class Solution 
{
public:
    bool canPartition(vector<int>& A) 
    {
        int sum = 0;
        for(int a:A)
            sum=sum+a;
        if(sum%2)
            return 0;
        
        int m = A.size();
        int n = sum/2;
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0] = true;
        for(int i = 1;i<=m;i++)
        {
            for(int j=0;j<=n;j++) //first column all true
            {
                if(j-A[i-1]>=0)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};