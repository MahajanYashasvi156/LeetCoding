/*
Link - https://leetcode.com/problems/longest-palindromic-subsequence/

TC - O(N^2)
SC - O(N^2)
*/
class Solution 
{
public:
    int longestPalindromeSubseq(string s) 
    {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int l = 1;l<=n;l++)
        {
            for(int i=0;i<=n-l;i++)
            {
                int j = i+l-1;
                
                if(l==1)
                    dp[i][j]=1;
                
                else if(l==2)
                {
                    if(s[i]==s[j])
                        dp[i][j]= 2;
                    else
                        dp[i][j]=1;
                }
                else
                {
                    if(s[i]==s[j])
                        dp[i][j]=2+dp[i+1][j-1];
        
                    else
                        dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }     
            }
        }
        return dp[0][n-1];
    }
};