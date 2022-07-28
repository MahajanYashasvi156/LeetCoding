class Solution 
{
    void dfs(vector<vector<int>>& grid,int &id,int &count,int i, int j)
    {
        if(i<0 or i>grid.size()-1 or j<0 or j>grid.size()-1)
            return;
        if(grid[i][j]!=1)
            return;
        
        count++;
        
        grid[i][j] = id;
        dfs(grid,id,count,i-1,j);
        dfs(grid,id,count,i,j-1);
        dfs(grid,id,count,i,j+1);
        dfs(grid,id,count,i+1,j);
    }
public:
    int largestIsland(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int id = 2;
        unordered_map<int,int>componentSize;
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int count = 0;
                    dfs(grid,id,count,i,j);
                    componentSize[id] = count;
                    id++;
                }
            }
        }
        
        int ans = 0;
        int flag = false;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    flag = true;
                    int count = 0;
                    vector<bool> taken(id+1,false);
                    if(i>0)
                    {
                        int compId = grid[i-1][j];
                        if(compId>1 and taken[compId]==false)
                        {
                            taken[compId]=true;
                            count+=componentSize[compId];
                        }
                    }
                    if(j>0)
                    {
                        int compId = grid[i][j-1];
                        if(compId>1 and taken[compId]==false)
                        {
                            taken[compId]=true;
                            count+=componentSize[compId];
                        }
                    }
                    if(j<grid.size()-1)
                    {
                        int compId = grid[i][j+1];
                        if(compId>1 and taken[compId]==false)
                        {
                            taken[compId]=true;
                            count+=componentSize[compId];
                        }
                    }
                    if(i<grid.size()-1)
                    {
                        int compId = grid[i+1][j];
                        if(compId>1 and taken[compId]==false)
                        {
                            taken[compId]=true;
                            count+=componentSize[compId];
                        }
                    }
                    ans = max(ans,count+1);
                }
            }
        }
        if(flag == false)
            return grid.size()*grid.size();
        return ans;
    }
};