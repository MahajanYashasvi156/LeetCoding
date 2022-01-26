/*
Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/


class Solution 
{
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        
        if(n<=1)
            return 0;
        
        vector<vector<int>> dp(k+1,vector<int>(n,0));
        
        for(int trans=1;trans<=k;trans++)
        {
            for(int day=1;day<n;day++)
            {
                int m = dp[trans][day-1];
                for(int prevdays=0;prevdays<day;prevdays++)
                {
                    m=max(dp[trans-1][prevdays]+(prices[day]-prices[prevdays]),m);
                }
                dp[trans][day]=m;
                
            }
        }
        return dp[k][n-1];
    }
};
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
        
        for(int trans=1;trans<=k;trans++)
        {
            int prevmax=-1*prices[0];
            for(int day=1;day<n;day++)
            {
               dp[trans][day]=max(dp[trans][day-1],prices[day]+prevmax);
               prevmax=max(prevmax,dp[trans-1][day]-prices[day]);
            }
        }
        return dp[k][n-1];
    }
};