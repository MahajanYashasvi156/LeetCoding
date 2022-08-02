/*
    1. greedy doesnt work here because sum of optimal solution of both path is not the optimal solution for complete problem. The move is dependent on the route of the other path so we need to make moves in both paths simultaneously.

    2. Instead of walking from end to beginning, let's reverse the second leg of the path, so we are only considering two paths from the beginning to the end.
    3. Notice, No of moves by path are equal as we are moving simulatenously. (start of both path is same) i1+j1 = i2+j2. We can find i2 = i1+j1-j2.

    Make a 3d DP,i1,j1,j2. As we want to move both  simultaneously. 
*/

class Solution 
{
public:
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int n = grid.size();
       
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,INT_MIN)));
        
        /*
            DP solution is bottom-up so we start with the smaller subproblem  i.e. both path reaching from n-1,n-1 to n-1,n-1.Where complete problem is to reaching(0,n-1).
        */
        for(int i1 = n-1;i1>=0 ;i1--)
        {
            for(int j1 = n-1;j1>=0;j1--)
            {
                for(int j2 = n-1;j2>=0;j2--)
                {
                    int i2 = i1+j1-j2;
                    
                    //Boundary case for derived index.
                    if(i2<0 || i2>=n) 
                        continue;
                    
                    //If any of the path got throne we can't go with this path.
                    if(grid[i2][j2]==-1 or grid[i1][j1]==-1)
                        continue;
                    
                    //Base case - final destination
                    if(i1==n-1 and j1==n-1 and j2==n-1 )
                        dp[i1][j1][j2] = grid[i1][j1];
                    else
                    {
                        int maxi = INT_MIN;
                        
                        //take a max of all possible move for both paths. There will be 4 cases . Both go down,down || down,right || right,down || right,right
                        if(j1<n-1 and i2<n-1)
                        {
                            maxi  =  max(maxi,dp[i1][j1+1][j2]);
                        }
                        if(j1<n-1 and j2<n-1)
                        {
                            maxi  =  max(maxi,dp[i1][j1+1][j2+1]);
                        }
                        if(i1<n-1 and i2<n-1)
                        {
                            maxi  =  max(maxi,dp[i1+1][j1][j2]);
                        }
                        if(i1<n-1 and j2<n-1)
                        {
                            maxi  =  max(maxi,dp[i1+1][j1][j2+1]);
                        }
                        
                        //if there exist a path to final destination 
                        if(maxi!=INT_MIN)
                        {
                            //If i1==i2 then j1==j2 so both are at same cell pick cherries only once.
                            if(i1==i2)
                            {
                                dp[i1][j1][j2] = grid[i1][j1] + maxi;
                            }
                            else 
                            {
                                dp[i1][j1][j2] = grid[i1][j1] + grid[i2][j2]+maxi;
                            }
                        }
                        
                    }
                }
                
            }
           
        }
        if(dp[0][0][0]==INT_MIN)
            return 0;
        return dp[0][0][0];
    }
};