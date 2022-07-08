/*
class Solution 
{
    int countCells(vector<vector<int> > &A,int i,int j,bool &blue,bool &red,vector<vector<bool>> &visited)
{
    if(i==0 ||j==0)
        blue = true;
    if(i==A.size()-1 || j==A[0].size()-1)
        red = true;
    
    if(red and blue)
        return 1;
    if(visited[i][j])
        return 0;
    visited[i][j] = 1;
    
    int ans = 0;
    if(i>0 and A[i-1][j]<=A[i][j])
        ans = countCells(A,i-1,j,blue,red,visited);
        
    if(!ans and  i<A.size()-1 and A[i+1][j]<=A[i][j])
        ans = countCells(A,i+1,j,blue,red,visited);
    
    
    if(!ans and  j>0 and A[i][j-1]<=A[i][j])
        ans = countCells(A,i,j-1,blue,red,visited);
        
    if(!ans and j<A[0].size()-1 and  A[i][j+1]<=A[i][j])
        ans = countCells(A,i,j+1,blue,red,visited);
    
    visited[i][j] = 0;
    return ans;
} 
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& A) 
    {
        int m = A.size();
        int n = A[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        vector<vector<int>> result;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                bool blue = false;
                bool red = false;
                if(countCells(A,i,j,blue,red,visited))
                    result.push_back({i,j});
            }
        }
        return result;
    }
};
*/

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
