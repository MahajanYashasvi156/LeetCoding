class Solution 
{
    int bfs(vector<vector<int>>&A,int i,int j)
    {
        int m = A.size();
        int n = A[0].size();

        queue<pair<int,int>>q;
        q.push({i,j});

        int regionCount = 0;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            regionCount++;
            if(x>0  and A[x-1][y]==1)
            {
                A[x-1][y]=-1;
                q.push({x-1,y});
            }
            if(x<m-1 and A[x+1][y]==1)
            {
                A[x+1][y]=-1;
                q.push({x+1,y});
            }   
            if(y>0 and A[x][y-1]==1)
            {
                A[x][y-1]=-1;
                q.push({x,y-1});
            }  
            if(y<n-1 and A[x][y+1]==1)
            {
                A[x][y+1]=-1;
                q.push({x,y+1});
            }
        }
        return regionCount;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& A)
    {
        int ans = 0;
        for(int i = 0;i<A.size();i++)
        {
            for(int j = 0;j<A[0].size();j++)
            {
                if(A[i][j]==1)
                {
                    A[i][j] = -1;
                    ans= max(ans,bfs(A,i,j));
                }
            }
        }
        return ans;
    }
};