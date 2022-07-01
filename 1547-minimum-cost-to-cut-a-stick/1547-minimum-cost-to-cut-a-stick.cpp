class Solution 
{
public:
    int minCost(int n, vector<int>& cuts) 
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        
        int m = cuts.size();
        
        vector<vector<int>> dp(m,vector<int>(m,0));
        
        for(int len = 2;len<m;len++)
        {
            for(int i = 0;i<m-len;i++)
            {
                int j = i+len;
                
                int mini = INT_MAX;
                for(int k = i+1;k<j;k++)
                    mini = min(mini,dp[i][k]+dp[k][j]);
                dp[i][j] = mini+cuts[j]-cuts[i];
            }
        }
        return dp[0][m-1];
    }
};