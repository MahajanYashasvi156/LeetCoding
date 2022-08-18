class Solution 
{
    int solve(vector<vector<int>>& matrix,int i,int j,vector<vector<bool>> &visited,vector<vector<int>> &dp)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int m = matrix.size();
        int n = matrix[0].size();

        visited[i][j]=true;
        int size = 1;
        
        if(i<m-1 and matrix[i][j]<matrix[i+1][j] and visited[i+1][j]==false)
            size = max(size,solve(matrix,i+1,j,visited,dp)+1);
        if(i>0 and matrix[i][j]<matrix[i-1][j] and visited[i-1][j]==false)
            size = max(size,solve(matrix,i-1,j,visited,dp)+1);
        if(j<n-1 and matrix[i][j]<matrix[i][j+1] and visited[i][j+1]==false)
            size = max(size,solve(matrix,i,j+1,visited,dp)+1);
        if(j>0 and matrix[i][j]<matrix[i][j-1] and visited[i][j-1]==false)
            size = max(size,solve(matrix,i,j-1,visited,dp)+1);
        
         visited[i][j]=false;
         return dp[i][j] = size;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int maxi = INT_MIN;
    
        vector<vector<bool>> visited(matrix.size(),vector<bool>(matrix[0].size(),false));
        
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[0].size();j++)
            {
                maxi = max(maxi,solve(matrix,i,j,visited,dp));
            }
        }
        
        return maxi;
    }
};