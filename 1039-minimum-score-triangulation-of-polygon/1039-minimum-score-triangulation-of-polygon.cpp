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
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int chainLength = 2;chainLength<=n-1;chainLength++)
        {
            for(int l = 1;l<=n-chainLength;l++)
            {
                int r = l+chainLength-1;
                
                dp[l][r] = INT_MAX;
                for(int p = l;p<r;p++)
                {
                    int currCost = dp[l][p] + dp[p+1][r] + values[l-1]*values[p]*values[r];

                    dp[l][r] = min(dp[l][r],currCost);
                }
            }
        }
        return dp[1][n-1];
    }
};

/*
class Solution 
{
    int MCM(vector<int>& values,vector<vector<int>>&dp,int l,int r)
    {
        if(l>=r)
            return 0;
        
        if(dp[l][r]!=-1)
            return dp[l][r];
        
        dp[l][r] = INT_MAX;
        for(int p = l;p<r;p++)
        {
            int currCost = MCM(values,dp,l,p) + MCM(values,dp,p+1,r) + values[l-1]*values[p]*values[r];
            
            dp[l][r] = min(dp[l][r],currCost);
        }
        return dp[l][r];
    }
public:
    int minScoreTriangulation(vector<int>& values) 
    {
        int n = values.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return MCM(values,dp,1,n-1);
    }
};

*/