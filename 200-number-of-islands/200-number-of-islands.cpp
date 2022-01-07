class Solution 
{
    void dfs(vector<vector<char>>& grid,int i,int j,int m,int n,vector<vector<bool>>& visited)
    {
        if(i<0 or i>=m or j<0 or j>=n or visited[i][j]==true or grid[i][j]=='0')
            return ;
        
        cout<<i<<" "<<j<<" "<<endl;
        
        visited[i][j]=true;
        //grid[i][j] = '-1';
        
        dfs(grid,i-1,j,m,n,visited);

        dfs(grid,i+1,j,m,n,visited);

        dfs(grid,i,j-1,m,n,visited);

        dfs(grid,i,j+1,m,n,visited);
        
    }
    
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int m=grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int islands=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j]==false and grid[i][j]=='1')
                {
                    islands++;
                    dfs(grid,i,j,m,n,visited);
                }
            }
        }
        return islands;
    }
};