class Solution
{
    int solve(vector<int>& group,vector<int>& profit,int index,int n,int minProfit,vector<vector<vector<int>>> &dp)
    {
        if(n==0 || index == group.size())
            return minProfit==0;
        
        if(dp[index][minProfit][n]!=-1)
            return dp[index][minProfit][n];
        int ans = 0;
        
        if(n>=group[index])
            ans = (ans + solve(group,profit,index+1,n-group[index],max(0,minProfit-profit[index]),dp))%1000000007;
        
        ans=  (ans +solve(group,profit,index+1,n,minProfit,dp))%1000000007;
       
        return dp[index][minProfit][n]=ans;
    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) 
    {
        int size =group.size();
        
        vector<vector<vector<int>>> dp(size+1,vector<vector<int>>(minProfit+1,vector<int>(n+1,-1)));
        
       return solve(group,profit,0,n,minProfit,dp);
    }
};