class Solution 
{
public:
    /* 
    int minPathSumRecursionTLE(vector<vector<int>>& grid,int row,int col)
    {
        if(row==grid.size()-1 and col==grid[0].size()-1)
            return grid[row][col];
        
        else if(row==grid.size() or col==grid[0].size() )
            return INT_MAX;
        
        int right= minPathSumRecursionTLE(grid,row,col+1);
        int down = minPathSumRecursionTLE(grid,row+1,col);
        
        return grid[row][col]+min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
         
        return minPathSumRecursionTLE(grid,0,0);
    }
    */
    /*
    int minPathSumMemoization(vector<vector<int>>& grid,int row,int col,vector<vector<int>>& dp)
    {
        if(row==grid.size()-1 and col==grid[0].size()-1)
            return grid[row][col];
        else if(row==grid.size() or col==grid[0].size() )
            return INT_MAX;
        
        if(dp[row][col]!=-1)
            return dp[row][col];
        
        int right= minPathSumMemoization(grid,row,col+1,dp);
        int down = minPathSumMemoization(grid,row+1,col,dp);
        
        return dp[row][col]=grid[row][col]+min(right,down);
    }
    
    int minPathSum(vector<vector<int>>& grid) 
    {
         vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
         return minPathSumMemoization(grid,0,0,dp);
    }
    */
    int minPathSumIterativeDP(vector<vector<int>>& grid,int row,int col,vector<vector<int>>& dp)
    {
        for(int i=row-1;i>=0;i--)
        {
            for(int j=col-1;j>=0;j--)
            {
                if(i==row-1 and j==col-1)
                {
                    dp[i][j]=grid[i][j];
                    continue;
                } 
                int right = INT_MAX;
                int down  = INT_MAX;
                if(j!=col-1)
                    right=dp[i][j+1];
                if(i!=row-1)
                    down=dp[i+1][j];
             
                dp[i][j]=grid[i][j]+min(right,down);
            }
        }
        return dp[0][0];
    }
        
    int minPathSum(vector<vector<int>>& grid) 
    {
         vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
         return minPathSumIterativeDP(grid,grid.size(),grid[0].size(),dp);
    }
    
};