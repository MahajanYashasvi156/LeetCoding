class Solution 
{
    public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> result(n,vector<int>(n));
        
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        int i;
        int j;
        int count = 1;
        while(left<=right and top<=bottom)
        {
            i = top;
            for(j=left;j<=right;j++)
            {
                result[i][j]=count++;
            }
        
            top++;
            j=right;
            for(i=top;i<=bottom;i++)
            {
                result[i][j]=count++;
            }
            right--;
            i=bottom;
            for(j=right;j>=left;j--)
            {
                result[i][j]=count++;
            }
            bottom--;
            j=left;
            for(i=bottom;i>=top;i--)
            {
                result[i][j]=count++;
            }
            left++;
        }
        
        return result;
       
        
    }
};