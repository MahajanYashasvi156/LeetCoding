class Solution 
{
public:
    int largestSubmatrix(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 1;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(matrix[i][j]==1)
                {
                    matrix[i][j] = matrix[i-1][j]+1;
                }
            }
        }
        
        int ans = 0;
        for(int i = 0;i<m;i++)
        {
            sort(matrix[i].begin(),matrix[i].end());
            for(int j = n-1;j>=0;j--)
            {
                int  height = matrix[i][j];
                
                int length = n-j;
                
                ans = max(ans,length*height);
            }
        }
        return ans;
        
    }
};