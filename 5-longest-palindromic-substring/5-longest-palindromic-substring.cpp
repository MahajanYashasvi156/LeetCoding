class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n));
        int maxLength = 0;
        int start = 0;
        int end = 0;
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
                    {
                        dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                    }
                }
                
                if(maxLength<dp[i][j])
                {
                    maxLength = dp[i][j];
                    start = i;
                    end = j;
                }
            }
        }
        return s.substr(start,maxLength);
    }
};