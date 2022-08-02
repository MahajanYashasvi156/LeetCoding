class Solution 
{
    int f(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        //Boundaru case
        if(j1<0 or j1>=n or j2<0 or j2>=n)
            return -1e8;
        //Destination case
        if(i==m-1)
        {
            if(j1==j2)
                return grid[i][j1];
            else
                return grid[i][j1]+grid[i][j2];
        }
        
        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
        
        int maxi = INT_MIN;
        
        //Explore all paths of both robots simultaneously
        
        for(int dj1 = -1;dj1<2;dj1++)
        {
            for(int dj2 = -1;dj2<2;dj2++)
            {
                if(j1==j2)
                {
                    maxi = max(maxi,grid[i][j1]+f(i+1,j1+dj1,j2+dj2,grid,dp));
                }
                else
                    maxi = max(maxi,grid[i][j1]+grid[i][j2]+f(i+1,j1+dj1,j2+dj2,grid,dp));
            }
        }
        return dp[i][j1][j2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        int j1 = 0;
        int j2 = n-1;
        
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        
        return f(0,j1,j2,grid,dp);
    }
};