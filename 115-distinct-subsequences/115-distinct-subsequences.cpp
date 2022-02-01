class Solution {
public:
    int numDistinct(string s, string t) 
    {
        int m = s.size();
        int n = t.size();
        vector<vector<long long>> dp(m+1,vector<long long>(n+1));
        dp[0][0]=1;
        for(int i=1;i<=m;i++)
        {
            for(int j = 0;j<=n;j++)
            {
                if(j==0)
                    dp[i][j]=1;
                else
                {
                    if(s[i-1]==t[j-1])
                        dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%1000000007;
                    else
                        dp[i][j]= dp[i-1][j];
                }
              
            }
           
        }
        return dp[m][n];
    }
    
};