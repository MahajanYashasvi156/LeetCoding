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
        {
            dp[i][j] = need;
        }
        return dp[i][j];
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        vector<vector<int>>dp(dungeon.size()+1,vector<int>(dungeon[0].size()+1,-1));
        return (-1)*solve(dungeon,0,0,dp)+1;
    }
};