class Solution
{
public:
    int uniquePaths(int m, int n) 
    {
        double totalSteps = m+n-2;
        
        int mini = min(m,n)-1;
        
        double ans = 1.0;
        for(int i = 0;i<mini;i++)
        {
            ans = ans*(totalSteps-i)/(i+1);
        }
        return ans;
    }
};

/*
class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m , vector<int>(n,0));
        
        for(int i = m-1;i>=0;i--)
        {
            for(int j = n-1;j>=0;j--)
            {
                if(i==m-1 and j==n-1)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    if(j<n-1)
                        dp[i][j] += dp[i][j+1];
                    if(i<m-1)
                        dp[i][j] += dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
};
*/