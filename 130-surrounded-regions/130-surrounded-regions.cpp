class Solution 
{
        void dfs(vector<vector<char>> &A,int i,int j,vector<vector<int>>&visited)
        {
            if(visited[i][j] || A[i][j]=='X')
                return;

            visited[i][j] = 1;
            A[i][j]='C';

            if(i<A.size()-1)
                dfs(A,i+1,j,visited);

            if(i>0)
                dfs(A,i-1,j,visited);

            if(j<A[0].size()-1)
                dfs(A,i,j+1,visited);

            if(j>0)
                dfs(A,i,j-1,visited); 
        }
public:
    void solve(vector<vector<char>>& A) 
    {
        int m = A.size();
        int n = A[0].size();

        vector<vector<int>>visited(m,vector<int>(n,0));

        for(int i = 0;i<m;i++)
            dfs(A,i,0,visited);

        for(int i = 0;i<m;i++)
            dfs(A,i,n-1,visited);

        for(int j = 0;j<n;j++)
                dfs(A,0,j,visited);

        for(int j = 0;j<n;j++)
                dfs(A,m-1,j,visited);

        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(A[i][j]=='C')
                    A[i][j]='O';
                else if(A[i][j]=='O')
                    A[i][j]='X';
            }
        }  
    }
};