class Solution 
{
public:
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,INT_MIN)));
        
        for(int i1 = n-1;i1>=0 ;i1--)
        {
            for(int j1 = n-1;j1>=0;j1--)
            {
                for(int j2 = n-1;j2>=0;j2--)
                {
                    int i2 = i1+j1-j2;
                    
                    if(i2<0 || i2>=n) 
                        continue;
                    
                    if(grid[i2][j2]==-1 or grid[i1][j1]==-1)
                        continue;
                    if(i1==n-1 and j1==n-1 and j2==n-1 )
                        dp[i1][j1][j2] = grid[i1][j1];
                    else
                    {
                        int maxi = INT_MIN;
                        
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
                        
                        if(maxi!=INT_MIN)
                        {
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