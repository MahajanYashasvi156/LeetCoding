class Solution
{
public:
    int minPathSum(vector<vector<int>>& A) 
    {
        int m = A.size();
        int n = A[0].size();
        for(int i = m-1;i>=0;i--)
        {
            for(int j = n-1;j>=0;j--)
            {
                if(i==m-1 and j==n-1)
                    continue;
                if(i==m-1)
                    A[i][j]+=A[i][j+1];
                else if(j==n-1)
                    A[i][j]+=A[i+1][j]; 
                else 
                    A[i][j]+=min(A[i][j+1],A[i+1][j]);
            }
        }
        return A[0][0];
    }
};

/* 
class Solution 
{
public:
    
    Link - https://leetcode.com/problems/minimum-path-sum/

    Recursion - TLE
    TC - O(2^(MN))
    Aux SC - O(M+N)

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
    Recursion - Memoization
    TC - O(MN)
    Aux SC - O(M+N)
    SC - O(MN)
    
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
    
    /*
    Iterative DP 
    TC - O(M*N)
    SC - O(M*N)
    
    Meaning of dp - Each cell will store minimum distance from that cell to target
    Smaller problem is min distance of last cell (n-1,m-1) to target (n-1,m-1)
    Bigger problem is min distance of last cell (0,0) to target (n-1,m-1)
    Traversal - Hence, bottom to up, right to left.
    
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
                //If there is no right and no down, then take it infinity.
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
*/
    