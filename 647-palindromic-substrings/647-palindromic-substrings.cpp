class Solution {
public:
    int countSubstrings(string s) 
    {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        int palSubStrings = 0;
        for(int l =1;l<=n;l++)
        {
            for(int i = 0;i<=n-l;i++)
            {
                int j = i+l-1;
                if(l==1)
                    dp[i][j]=true;
                else if(l==2)
                    dp[i][j]=s[i]==s[j];   
                else
                {
                    if(s[i]==s[j] and dp[i+1][j-1])
                        dp[i][j]=true;
            
                    else
                        dp[i][j]=false;
                }
                if(dp[i][j])
                    palSubStrings++;
            }
        } 
        return palSubStrings;
    }
};