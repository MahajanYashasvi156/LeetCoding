/*
Link - https://leetcode.com/problems/perfect-squares/
TC - O(N*root(N))
SC - O(N)
*/
class Solution 
{
public:
    int numSquares(int n) 
    {
        vector<int> dp(n+1);
        int count = 0;
        for(int i=1;i<=n;i++)
        {
            int mincount = INT_MAX;
            for(int j=sqrt(i);j>0;j--)
            {
                mincount=min(mincount,dp[i-j*j]);
            }
            dp[i]=mincount+1;
        }
        return dp[n];
    }
};