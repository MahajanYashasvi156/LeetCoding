/*
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& A) 
    {
        int m = A.size();
        int n = A[0].size();
        if(A[0][0] || A[m-1][n-1])
            return 0;
        
        for(int i = m-1;i>=0;i--)
        {
            for(int j = n-1;j>=0;j--)
            {
                if(A[i][j]==0)
                {
                    if(i<m-1)
                         A[i][j] = (long(A[i][j]) + A[i+1][j])%INT_MAX;
                    if(j<n-1)
                        A[i][j] = (long(A[i][j])+ A[i][j+1])%INT_MAX;
                    if(i==m-1 and j==n-1)
                        A[i][j] = 1;
                }
                else
                     A[i][j] = 0;
            }
        }
        return A[0][0];
        
    }
};

*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& A) 
    {
        int m = A.size();
        int n = A[0].size();
        if(A[0][0] || A[m-1][n-1])
            return 0;
        vector<vector<long long>> dp(m,vector<long long>(n,0));
        dp[m-1][n-1] = 1;

        for(int i = m-1;i>=0;i--)
        {
            for(int j = n-1;j>=0;j--)
            {
                if(A[i][j]==0)
                {
                    if(i<m-1)
                         dp[i][j] = dp[i][j] + dp[i+1][j];
                    if(j<n-1)
                        dp[i][j] = dp[i][j]+ dp[i][j+1];
                }
            }
        }
        return dp[0][0];
        
    }
};