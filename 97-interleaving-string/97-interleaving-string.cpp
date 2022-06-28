class Solution 
{
public:
    bool isInterleave(string A, string B, string C) 
    {
        if(A.size()+B.size()!=C.size())
            return false;
        vector<vector<bool>> dp(A.size()+1,vector<bool>(B.size()+1,false));
        dp[0][0]=1;
        for(int i = 0;i<=A.size();i++)
        {
            for(int j = 0;j<=B.size();j++)
            {
                if(i>0 and A[i-1]==C[i+j-1])
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                if(j>0 and B[j-1]==C[i+j-1])
                    dp[i][j] = dp[i][j] || dp[i][j-1];
            }
        }
        return dp[A.size()][B.size()];
    }
};