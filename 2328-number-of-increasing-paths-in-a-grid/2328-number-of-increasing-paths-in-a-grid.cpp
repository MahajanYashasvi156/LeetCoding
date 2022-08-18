class Solution 
{
    int M = 1000000007;
    int solve(vector<vector<int>>& matrix,int i,int j,vector<vector<bool>> &visited,vector<vector<int>> &dp)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int m = matrix.size();
        int n = matrix[0].size();

        visited[i][j]=true;
        int size = 1;
        
        if(i<m-1 and matrix[i][j]<matrix[i+1][j] and visited[i+1][j]==false)
            size = (size + solve(matrix,i+1,j,visited,dp))%M;
        if(i>0 and matrix[i][j]<matrix[i-1][j] and visited[i-1][j]==false)
            size = (size + solve(matrix,i-1,j,visited,dp))%M;
        if(j<n-1 and matrix[i][j]<matrix[i][j+1] and visited[i][j+1]==false)
            size = (size + solve(matrix,i,j+1,visited,dp))%M;
        if(j>0 and matrix[i][j]<matrix[i][j-1] and visited[i][j-1]==false)
            size = (size +  solve(matrix,i,j-1,visited,dp))%M;
        
         visited[i][j]=false;
         return dp[i][j] = size;
    }
    
public:
    int countPaths(vector<vector<int>>& matrix) 
    {
        int count = 0;
    
        vector<vector<bool>> visited(matrix.size(),vector<bool>(matrix[0].size(),false));
        
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[0].size();j++)
                count = (count +solve(matrix,i,j,visited,dp))%M;
        }
        
        return count;
        
    }
};