class Solution 
{
    void solve(vector<vector<int>>& grid,int si,int sj,int di,int dj,vector<vector<int>>&visited,int &result)
    {
        if(si<0 || si>grid.size()-1 || sj<0 || sj>grid[0].size()-1|| visited[si][sj] || grid[si][sj]==-1)
            return;
        
        if(si==di and sj==dj)
        {
            for(int i=0;i<grid.size();i++)
            {
                for(int j = 0;j<grid[0].size();j++)
                {
                    if(grid[i][j]==0 and visited[i][j]==0)
                        return;
                }
            }
            result++;
            return;
        }
        
        visited[si][sj] = 1;
        solve(grid,si-1,sj,di,dj,visited,result); 
        solve(grid,si,sj-1,di,dj,visited,result); 
        solve(grid,si+1,sj,di,dj,visited,result); 
        solve(grid,si,sj+1,di,dj,visited,result); 
        visited[si][sj] = 0;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int si,sj,di,dj;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    si=i;
                    sj=j;
                }
                if(grid[i][j]==2)
                {
                    di=i;
                    dj=j;
                }
            }
        }
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size()));
        int result = 0;
        solve(grid,si,sj,di,dj,visited,result);    
        return result;
    }
};