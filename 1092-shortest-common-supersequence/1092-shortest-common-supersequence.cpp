class Solution 
{
    string getSCS(int m,int n,string s1,string s2,vector<vector<int>>&dp)
    {
        if(m==0 and n==0)
            return "";
        if(m==0)
            return  getSCS(m,n-1,s1,s2,dp)+s2[n-1];
        if(n==0)
            return  getSCS(m-1,n,s1,s2,dp)+s1[m-1];
        
        if(s1[m-1]==s2[n-1])
        {
            return getSCS(m-1,n-1,s1,s2,dp)+ s1[m-1] ;
        }
        
        if(dp[m-1][n]>dp[m][n-1])
            return  getSCS(m-1,n,s1,s2,dp)+s1[m-1];
        return  getSCS(m,n-1,s1,s2,dp)+s2[n-1];
    }
public:
    string shortestCommonSupersequence(string str1, string str2) 
    {
        vector<vector<int>>dp(str1.size()+1,vector<int>(str2.size()+1,0));
            
        for(int i = 1;i<=str1.size();i++)
        {
            for(int j = 1;j<=str2.size();j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return getSCS(str1.size(),str2.size(),str1,str2,dp);
    }
};