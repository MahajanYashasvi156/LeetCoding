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
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=sqrt(i);j>=0;j--)
            {
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};