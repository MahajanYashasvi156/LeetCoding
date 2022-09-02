class Solution {
public:
    int numRollsToTarget(int n, int k, int target) 
    {
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        
        dp[0][0] = 1;
        
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=target;j++)
            {
                int ways = 0;
                for(int f = 1;f<=k;f++)
                {
                    if(j>=f)
                        ways =(ways + dp[i-1][j-f])%1000000007;
                }
                
                dp[i][j] = ways;
            }
        }
        
        return dp[n][target];
    }
};


/*
class Solution 
{
    int solve(int index, int target,vector<vector<int>>&dp,int k)
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
*/