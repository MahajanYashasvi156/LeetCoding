/*
class Solution 
{
    int lcsRecursive(string text1,string text2,int i,int j)
    {
        if(i>=text1.size() or j>=text2.size())
            return 0;
        if(text1[i]==text2[j])
            return 1+ lcsRecursive(text1,text2,i+1,j+1);
        else
            return max(lcsRecursive(text1,text2,i+1,j),lcsRecursive(text1,text2,i,j+1));
    }
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        return lcsRecursive(text1,text2,0,0);
    }
};
*/
/*
class Solution 
{
    int lcsRecursive(string &text1,string 
    &text2,int i,int j,vector<vector<int>>&dp)
    {
        
        if(i>=text1.size() or j>=text2.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(text1[i]==text2[j])
            return dp[i][j] = 1+ lcsRecursive(text1,text2,i+1,j+1,dp);
        else
            return dp[i][j] = max(lcsRecursive(text1,text2,i+1,j,dp),lcsRecursive(text1,text2,i,j+1,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return lcsRecursive(text1,text2,0,0,dp);
    }
};

*/
class Solution 
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 or j==0)
                    dp[i][j]=0;
                else if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else 
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
