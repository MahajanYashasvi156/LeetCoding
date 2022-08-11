/*
class Solution 
{
    int solve(vector<vector<int>>& dungeon,int i,int j,vector<vector<int>>&dp)
    {   
        if(i==dungeon.size()-1 and j==dungeon[0].size()-1)
        {
            return min(dungeon[i][j],0);
        }
        if(i>=dungeon.size() || j>=dungeon[0].size())
            return INT_MIN;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int need = max(solve(dungeon,i+1,j,dp),solve(dungeon,i,j+1,dp));
        
        need = need + dungeon[i][j];
        if(need>0)
            dp[i][j] = 0;
        else
            dp[i][j] = need;
    
        return dp[i][j];
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        vector<vector<int>>dp(dungeon.size()+1,vector<int>(dungeon[0].size()+1,-1));
        return (-1)*solve(dungeon,0,0,dp)+1;
    }
};
*/

class Solution 
{
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        vector<vector<int>>dp(m,vector<int>(n,INT_MIN));
        
        int need ;
        for(int i = m-1;i>=0;i--)
        {
            for(int j = n-1;j>=0;j--)
            {
                if(i==m-1 and j==n-1)
                    need = dungeon[i][j];
                else if(i==m-1)
                    need = dp[i][j+1] + dungeon[i][j];
                else if(j==n-1)
                    need = dp[i+1][j] + dungeon[i][j];
                else
                    need = max(dp[i+1][j],dp[i][j+1]) + dungeon[i][j];
                if(need<0)
                    dp[i][j] = need;
                else
                    dp[i][j] = 0;
            }
        }
        return (-1)*dp[0][0]+1;
    }
};
