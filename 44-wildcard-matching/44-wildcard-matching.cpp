/*
Link - https://leetcode.com/problems/wildcard-matching/
TC - O(N^2)
SC - O(N^2)
*/

class Solution 
{
public:
    bool isMatch(string s, string p) 
    {
        int ssize = s.size();
        int psize = p.size();
        vector<vector<bool>> dp(psize+1,vector<bool>(ssize+1));
        
        dp[0][0]=true;
        
        for(int i=1;i<=psize;i++)
        {
            for(int j=0;j<=ssize;j++)
            {
                if(j==0)
                {
                    if(p[i-1]=='*')
                        dp[i][j]=dp[i-1][j];
                }
                else if(s[j-1]==p[i-1])
                    dp[i][j]=dp[i-1][j-1];
                else if(p[i-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[i-1]=='*')
                    dp[i][j]=dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
                else 
                    dp[i][j]=false;
            }
        }
        return dp[psize][ssize];
    }
};