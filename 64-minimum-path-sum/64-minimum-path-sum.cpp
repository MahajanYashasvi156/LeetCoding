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
};