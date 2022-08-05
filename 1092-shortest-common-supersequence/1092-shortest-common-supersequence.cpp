/*
    Application of LCS
*/
class Solution 
{
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
        
        int m = str1.size();
        int n = str2.size();
        string result;
        while(m>0 or n>0)
        {
            if(m==0 )
            {
                result = str2[n-1] +result;
                n--;
            }
            else if(n==0 )
            {
                result = str1[m-1] +result;
                m--;
            }  
            else if(str1[m-1]==str2[n-1])
            {
                result = str2[n-1] +result;
                n--;
                m--;
            }
            else if(dp[m-1][n]<=dp[m][n-1])
            {
                result = str2[n-1] +result;
                n--;
            }
            else
            {
                result = str1[m-1] +result;
                m--;
            }
        }
        return result;
    }
};

