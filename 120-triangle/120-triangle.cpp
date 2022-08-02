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