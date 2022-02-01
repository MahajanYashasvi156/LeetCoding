/*
Link - https://leetcode.com/problems/longest-palindromic-substring/submissions/

TC - O(N^2)
SC - O(N^2)

class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n));
        int maxLength = 0;
        int start = 0;
        for(int l = 1 ; l<=n;l++)
        {
            for(int i = 0;i<=n-l ;i++)
            {
                int j = i+l-1;
                
                if(l==1)
                    dp[i][j]=1;
                else if (l==2)
                {
                    if(s[i]==s[j])
                        dp[i][j]=2;
                    else
                        dp[i][j]=1;
                }
                else
                {
                    if(s[i]==s[j] and dp[i+1][j-1]==l-2)
                        dp[i][j]=dp[i+1][j-1]+2;
                
                    else
                        dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                
                }
                if(maxLength<dp[i][j])
                {
                    maxLength = dp[i][j];
                    start = i;
                }
            }
        }
        return s.substr(start,maxLength);
    }
};
*/
/*
Link - https://leetcode.com/problems/longest-palindromic-substring/submissions/

Optimized- 
TC - O(N^2)
SC - O(N^2)

Similar as count palindromic substrings.
*/
class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int n = s.size();
        vector<vector<bool>>dp(n,vector<bool>(n));
        
        int maxLength = 0;
        int start = 0;
        
        for(int l = 1 ; l<=n;l++)
        {
            for(int i = 0;i<=n-l ;i++)
            {
                int j = i+l-1;
                
                if(l==1)
                    dp[i][j]=true;
                
                else if (l==2)
                {
                    if(s[i]==s[j])
                        dp[i][j]=true;
                    else
                        dp[i][j]=false;
                }
                else
                {
                    if(s[i]==s[j] and dp[i+1][j-1])
                        dp[i][j]=true;
                    else
                        dp[i][j]=false;
                }
                if(dp[i][j])
                {
                    maxLength = l;
                    start = i;
                }
            }
        }
        return s.substr(start,maxLength);
    }
};