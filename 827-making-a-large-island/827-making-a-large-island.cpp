/*
Link - https://leetcode.com/problems/making-a-large-island/submissions/

Brute Force - Replace each of the 0 with 1 one by one then find the size of the compoennt including that cell using dfs. 

Optimized Approach - Assign an unique ID to all the cells of the component. Store the size of the component corresponding to its ID in a map to access later.

Note :- After this all 1 will get replaced by its corresponding component id in the grid. Only 0 will remain as it is. 

Traverse the grid if there is 0 then correponding size of component = 1(currentCell) + size of unique components of 4 directions.

If there is no Zero then the complete grid is a single component.

TC - O(N^2)
SC - O(N^2) 
*/
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