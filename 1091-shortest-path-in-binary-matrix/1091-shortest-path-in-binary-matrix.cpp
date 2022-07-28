class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        queue<pair<int,int>> q;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        
        int ans = -1;
        
        if(grid[0][0]==0)
        {
            q.push({0,0});
            visited[0][0] = 1;
            ans=1;
        }
        
        while(!q.empty())
        {
            int size = q.size();
            for(int k = 0;k<size;k++)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                if(i==grid.size()-1 and j == grid[0].size()-1)
                    return ans;
                if(i>0 and j>0 and grid[i-1][j-1]==0 and visited[i-1][j-1]==0)
                {
                    visited[i-1][j-1] = 1;
                    q.push({i-1,j-1});
                }
                if(i>0 and grid[i-1][j]==0 and visited[i-1][j]==0)
                {
                    visited[i-1][j] = 1;
                    q.push({i-1,j});
                }
                if(i>0 and j<grid[0].size()-1 and grid[i-1][j+1]==0 and visited[i-1][j+1]==0)
                {
                    visited[i-1][j+1] = 1;
                    q.push({i-1,j+1});
                }
                if( j>0 and grid[i][j-1]==0 and visited[i][j-1]==0)
                {
                    visited[i][j-1] = 1;
                    q.push({i,j-1});
                }
                if(j<grid[0].size()-1 and grid[i][j+1]==0 and visited[i][j+1]==0)
                {
                    visited[i][j+1] = 1;
                    q.push({i,j+1});
                }
                if(j>0 and i<grid.size()-1 and grid[i+1][j-1]==0 and visited[i+1][j-1]==0)
                {
                    visited[i+1][j-1] = 1;
                    q.push({i+1,j-1});
                }
                if(i<grid.size()-1 and grid[i+1][j]==0 and visited[i+1][j]==0)
                {
                    visited[i+1][j] = 1;
                    q.push({i+1,j});
                }
                if(i<grid.size()-1 and j<grid[0].size()-1 and grid[i+1][j+1]==0 and visited[i+1][j+1]==0)
                {
                    visited[i+1][j+1] = 1;
                    q.push({i+1,j+1});
                }
            }
            ans++;
        }
        return -1;
    }
};