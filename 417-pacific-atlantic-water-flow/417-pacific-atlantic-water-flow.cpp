class Solution 
{
        void countCells(vector<vector<int> > &A,vector<vector<bool>>&visited,int i,int j)
    {
        if(visited[i][j])
            return;

        visited[i][j] = true;

        if(i>0 and A[i][j]<=A[i-1][j])
            countCells(A,visited,i-1,j);

        if(i<A.size()-1 and A[i][j]<=A[i+1][j])
            countCells(A,visited,i+1,j);

        if(j>0 and A[i][j]<=A[i][j-1])
            countCells(A,visited,i,j-1);

        if(j<A[0].size()-1 and A[i][j]<=A[i][j+1])
            countCells(A,visited,i,j+1);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& A) 
    {
        int m = A.size();
        int n = A[0].size();
        vector<vector<bool>> visitedRed(m,vector<bool>(n,false));
        vector<vector<bool>> visitedBlue(m,vector<bool>(n,false));
        
        for(int i = 0;i<m;i++)
            countCells(A,visitedBlue,i,0);

        for(int j = 0;j<n;j++)
            countCells(A,visitedBlue,0,j);

        for(int i = 0;i<m;i++)
            countCells(A,visitedRed,i,n-1);

        for(int j = 0;j<n;j++)
            countCells(A,visitedRed,m-1,j);

        vector<vector<int>> result;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(visitedBlue[i][j] and visitedRed[i][j])
                    result.push_back({i,j});
            }
        }
        return result;
    }
};