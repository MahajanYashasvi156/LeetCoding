class Solution 
{
public:
    int minScoreTriangulation(vector<int>& values) 
    {
        int n = values.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        
        for(int l = 0;l<n;l++)
        {
            for(int i=0;i<n-l;i++)
            {
                int j = l+i;
                
                if(l==0 or l==1)
                {
                    dp[i][j]=0;
                }
                else 
                {
                    for(int k = i+1; k<j;k++)
                    {
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+ values[i]*values[k]*values[j]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};