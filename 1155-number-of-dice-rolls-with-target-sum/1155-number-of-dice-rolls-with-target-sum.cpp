class Solution 
{
    long long solve(int index, int target,vector<vector<int>>&dp,int k)
    {
        if(target<0)
            return 0;
        
        if(index==dp.size())
        {
            return target==0;
        }
        if(dp[index][target]!=-1)
            return dp[index][target];
        
        int ways = 0;
        for(int i = 1;i<=k;i++)
        {
            ways =(ways + solve(index+1,target-i,dp,k))%1000000007;
        }
        return dp[index][target] = ways;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        
        return solve(0,target,dp,k);
        
    }
};