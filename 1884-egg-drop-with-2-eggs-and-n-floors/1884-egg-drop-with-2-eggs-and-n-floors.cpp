class Solution 
{
    
    int findMoves(int floors,int x,vector<vector<int>>&dp)
    {
        if(x==1 )
            return floors;
        if(floors<=2)
            return floors;
        if(dp[floors][x]!=-1)
            return dp[floors][x];
        int ans = INT_MAX;
        for(int k = 1;k<=floors;k++)
        {
            ans = min(ans,1+max(findMoves(k-1,x-1,dp) ,findMoves(floors-k,x,dp)));
        }
        return dp[floors][x] = ans;
        
    }
public:
    int twoEggDrop(int n) 
    {    
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return findMoves(n,2,dp);
    }
};