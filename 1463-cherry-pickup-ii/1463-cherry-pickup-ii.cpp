/*
TC - O(MNN*9)
SC - O(MNN)
ASC - O(M);
*/

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
     
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n)));
        
        //Bottom - Up approach . Start solving from m-1.
        
        for(int j1 = 0;j1<n;j1++)
        {
            for(int j2 = 0;j2<n;j2++)
            {
                if(j1==j2)
                    dp[m-1][j1][j2] = grid[m-1][j1] ;
                else
                    dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
            }
        }
        
        for(int i = m-2;i>=0;i--)
        {
            for(int j1 = 0;j1<n;j1++)
            {
                for(int j2 = 0;j2<n;j2++)
                {
                    if(j1==j2)
                        dp[i][j1][j2] = grid[i][j1] ;
                    else
                        dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
                    
                    int maxi = 0;
                    
                    for(int dj1 = -1;dj1<2;dj1++)
                    {
                        for(int dj2 = -1;dj2<2;dj2++)
                        {
                            if(j1+dj1>=0 and j1+dj1<n  and j2+dj2>=0 and j2+dj2<n)
                                maxi = max(maxi,dp[i+1][j1+dj1][j2+dj2]);
                        }
                    }
                    dp[i][j1][j2] +=  maxi;
                }
            }
        }
        return dp[0][0][n-1];
    }
};



/*
TC - O(MNN*9)
SC - O(MNN)
ASC - O(M);
*/
/*
class Solution 
{
    int f(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        //Boundary case - robots are not allowed to move beyond grid.
        if(j1<0 or j1>=n or j2<0 or j2>=n)
            return -1e8;
        
        //Destination case
        if(i==m-1)
        {
            //If both robots are at the same cell then add them only once else add both cells cherries.
            if(j1==j2)
                return grid[i][j1];
            else
                return grid[i][j1]+grid[i][j2];
        }
        
        //Memoization
        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
        
        
        int maxi = INT_MIN;
        
        
        // Explore all paths of both robots simultaneously.
         //  Now from the current position. One robot can move to j1-1,j1,j1+1 of next row. Corresponding to each of this move another robot can move j2-1,j2,j2+1.
          //  So there will be 9 paths. Take maximum out of all paths.
        
        
        
        for(int dj1 = -1;dj1<2;dj1++)
        {
            for(int dj2 = -1;dj2<2;dj2++)
            {
                int currentRowCherries = 0;
                
                if(j1==j2)
                {
                    currentRowCherries = grid[i][j1];
                }
                else
                {
                    currentRowCherries = grid[i][j1] + grid[i][j2];
                }
                //Pick cherries for current row and then move to next row.
                maxi = max(maxi,currentRowCherries+f(i+1,j1+dj1,j2+dj2,grid,dp));
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
        
        /*
        Make a 3d DP. As we want to move both robots simultaneously. 
        Now for this two robots their positions will be i1,j1,i2,j2.
        But one can notice that both robots in 1 move goto next row together so both will be on same row together. We can have 3 paramenters i,j1,j2.
        
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        
        return f(0,j1,j2,grid,dp);
    }
};
*/