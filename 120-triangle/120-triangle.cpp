class Solution 
{
public:
    int minimumTotal(vector<vector<int>>& A) 
    {
        int n=A.size();
    
        for(int i = n-2;i>=0;i--)
        {
            for(int j = 0;j<A[i].size();j++)
            {
                A[i][j]+=min(A[i+1][j+1],A[i+1][j]);
            }
        }
        return A[0][0];
    }
};

/*
class Solution 
{
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        vector<int> dp(triangle.size(),INT_MAX);
        
        dp[0] =  triangle[0][0];
        
        for(int i = 1;i<triangle.size();i++)
        {
            for(int j = i;j>=0;j--)
            {
                int prev = dp[j];
                
                if(j>0)
                    prev = min(prev,dp[j-1]);
               
                dp[j] = triangle[i][j]+ prev;
            }
        }
        
        return *min_element(dp.begin(),dp.end());
    }
};
*/