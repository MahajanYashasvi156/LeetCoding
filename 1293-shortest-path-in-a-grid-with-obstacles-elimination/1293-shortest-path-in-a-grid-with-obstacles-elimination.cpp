/*
BFS + DP

Time Complexity - O(M*N*K)
Space Complexity- O(M*N)

here visited works as DP which stores the maximum obstacles that can be removable from a cell.

So if  a cell is not visited earlier then we have to visit it.
But if the cell is visited earlier but this time we can eliminate more number of obstacles then also we need to visit that cell again. Because it might possible in earlier we might not able to visit destination cell because of shortage of k value.


*/
class Solution 
{
public:
    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        int steps = 0;
        
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),-1));
        
        if(grid[0][0]==1)
        {
            q.push({k-1,{0,0}});
            visited[0][0] = k-1;
        }
        else
        {
            q.push({k,{0,0}});
            visited[0][0] = k;
        }
        
        
        while(!q.empty())
        {
            int s = q.size();
            for(int i = 0;i<s;i++)
            {
                int rem = q.front().first;
                int x = q.front().second.first;
                int y = q.front().second.second;
                q.pop();
                if(x == grid.size()-1 and y == grid[0].size()-1)
                    return steps;
                if(x>0 and (visited[x-1][y]==-1 or visited[x-1][y]<rem) and (rem>0 or grid[x-1][y]==0))
                {
                    if(grid[x-1][y]==1)
                    {
                         q.push({rem-1,{x-1,y}});
                         visited[x-1][y] = rem-1;   
                    }
                    else
                    {
                         q.push({rem,{x-1,y}});
                         visited[x-1][y] = rem;
                    }
                }
                
                if(x<grid.size()-1 and (visited[x+1][y]==-1 or visited[x+1][y]<rem) and (rem>0 or grid[x+1][y]==0))
                {
                    if(grid[x+1][y]==1)
                    {
                         q.push({rem-1,{x+1,y}});
                         visited[x+1][y] = rem-1;   
                    }
                    else
                    {
                         q.push({rem,{x+1,y}});
                         visited[x+1][y] = rem;
                    }
                }
                
                if(y>0 and (visited[x][y-1]==-1 or visited[x][y-1]<rem) and (rem>0 or grid[x][y-1]==0))
                {
                    if(grid[x][y-1]==1)
                    {
                         q.push({rem-1,{x,y-1}});
                         visited[x][y-1] = rem-1;
                    } 
                    else
                    {
                         q.push({rem,{x,y-1}});
                         visited[x][y-1] = rem;
                    }
                   
                }
                
                if(y<grid[0].size()-1 and (visited[x][y+1]==-1 or visited[x][y+1]<rem) and (rem>0 or grid[x][y+1]==0))
                {
                    if(grid[x][y+1]==1)
                    {
                         q.push({rem-1,{x,y+1}});
                         visited[x][y+1] = rem-1;
                    } 
                    else
                    {
                         q.push({rem,{x,y+1}});
                         visited[x][y+1] = rem;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};