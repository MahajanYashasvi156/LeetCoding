class NumMatrix 
{
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix) 
    {
        int r = matrix.size();
        int c= matrix[0].size();
        dp.resize(r, vector<int> (c,0));
        for(int i = r-1;i>=0;i--)
        {
            for(int j = c-1;j>=0;j--)
            {
                if(i<r-1 and j <c-1)
                {
                    dp[i][j] = matrix[i][j]+dp[i+1][j]+dp[i][j+1] - dp[i+1][j+1];
                }
                else if(i<r-1)
                {
                    dp[i][j] = matrix[i][j]+dp[i+1][j];
                }
                else if(j<c-1)
                {
                    dp[i][j] = matrix[i][j]+dp[i][j+1];
                }
                else
                    dp[i][j] = matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        int r = dp.size();
        int c= dp[0].size();
        
        if(row2<r-1 and col2<c-1)
            return  dp[row1][col1] - dp[row2+1][col1] - dp[row1][col2+1] + dp[row2+1][col2+1];
        
        else if(row2<r-1)
            return  dp[row1][col1] - dp[row2+1][col1];
        else if(col2<c-1)
            return  dp[row1][col1] - dp[row1][col2+1];
        return dp[row1][col1];
                
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */