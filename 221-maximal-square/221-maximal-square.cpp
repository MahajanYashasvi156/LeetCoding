class Solution 
{
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int maxArea = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 or j ==0)
                    dp[i][j]=matrix[i][j]-'0';
                else if(matrix[i][j]=='1' and dp[i][j-1]>0 and dp[i-1][j]>0 and dp[i-1][j-1]>0)
                {
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                }
                else
                    dp[i][j]=matrix[i][j]-'0';
                maxArea=max(maxArea,dp[i][j]*dp[i][j]);
            }
        }
        return maxArea;
    }
};