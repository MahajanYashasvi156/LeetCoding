/*
    Using Gap Strategy
*/
class Solution {
public:
    int minInsertions(string s)
    {
        int n = s.size();
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int len = 1;len<=n;len++)
        {
            for(int i = 0;i<=n-len;i++)
            {
                int j = i+len-1;
                
                if(i==j)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j] = dp[i+1][j-1];
                    }
                    else
                    {
                        dp[i][j] = min(dp[i+1][j],dp[i][j-1])+1;
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};


/*

LCS Based Solution - 

class Solution 
{
public:
    int minInsertions(string s) 
    {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        string s2 = s;
        reverse(s2.begin(),s2.end());
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                if(s[i-1] == s2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    
                }
            }
        }
        return n - dp[n][n];
        
    }
};
*/