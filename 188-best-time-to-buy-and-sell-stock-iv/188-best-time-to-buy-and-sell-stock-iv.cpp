
/*
Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
TC - O(N^2 * K)
SC - O(NK)

Approach 1 -
dp[t][d] stores max profit till dth day with at most t transactions


class Solution 
{
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        
        if(n<=1)
            return 0;
        
        vector<vector<int>> dp(k+1,vector<int>(n,0));
        
        for(int t=1;t<=k;t++)
        {
            for(int d=1;d<n;d++)
            {
                int m = dp[t][d-1];
                for(int pd=0;pd<d;pd++)
                {
                    m=max(dp[t-1][pd]+(prices[d]-prices[pd]),m);
                }
                dp[t][d]=m;
                
            }
        }
        return dp[k][n-1];
    }
};
*/
/*

TC - O(NK)
SC - O(NK)

Approach 2 - Slightly diff than above approach. We are maintaining prevmax just because we don't need to loop through previous days to see what was the profit they did to complete one less transactions than current. 
*/


class Solution 
{
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        
        if(n<=1)
            return 0;
        
        vector<vector<int>> dp(k+1,vector<int>(n,0));
        
        for(int t=1;t<=k;t++)
        {
            int prevmax=dp[t-1][0]-prices[0];
            for(int d=1;d<n;d++)
            {
               dp[t][d]=max(dp[t][d-1],prices[d]+prevmax);
               prevmax=max(prevmax,dp[t-1][d]-prices[d]);
            }
        }
        return dp[k][n-1];
    }
};