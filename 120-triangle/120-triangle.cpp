/*
class Solution 
{
public:
    int minimumTotal(vector<vector<int>>& A) 
    {
        int n=A.size();
    
        for(int i = n-2;i>=0;i--)
        {
            for(int j = 0;j<A[i].size();j++)
            {
                A[i][j]+=min(A[i+1][j+1],A[i+1][j]);
            }
        }
        return A[0][0];
    }
};
*/

class Solution 
{
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<int> dp(n);
        
        for(int i = 0;i<n;i++)
            dp[i] = triangle[n-1][i];
        
        for(int i = n-2;i>=0;i--)
        {
            for(int j = 0;j<=i;j++)
            {
                int prev = dp[j];
                
                if(j<n-1)
                    prev = min(prev,dp[j+1]);
               
                dp[j] = triangle[i][j]+ prev;
            }
        }
        
        return dp[0];
    }
};
