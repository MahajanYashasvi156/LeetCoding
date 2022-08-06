/*
Link - https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
TC - O(N^3)
SC - O(N^2)

Gap strategy on DP same as MCM Baloon Birst

We will take base of polygon and will form all possible triangles and this will give us subproblems 
abcde, aec as triangle will give subproblems as abc cde whose values are already calculated
so ans for abcde = ans for abc + ans for cde + a*e*c
*/

class Solution 
{
public:
    int minScoreTriangulation(vector<int>& values) 
    {
        int n = values.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int l = 2;l<n;l++)
        {
            for(int i=0;i<n-l;i++)
            {
                int j = l+i;
                dp[i][j] = INT_MAX;
                
                for(int k = i+1; k<j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+ values[i]*values[k]*values[j]);
                }
            }
            
        }
        return dp[0][n-1];
    }
};