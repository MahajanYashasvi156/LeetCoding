class Solution 
{
public:
    int minFallingPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        for(int i = n-2;i>=0;i--)
        {
            for(int j = n-1;j>=0;j--)
            {
                int minPath = INT_MAX;
                for(int k = 0;k<n;k++)
                {
                    if(k!=j)
                        minPath = min(minPath,grid[i+1][k]);
                }
                grid[i][j] +=  minPath;
            }
        }
        return *min_element(grid[0].begin(),grid[0].end());
    }
};