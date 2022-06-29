class Solution 
{
public:
    int numDecodings(string A) 
    {
        vector<long> dp(A.size()+1);
        dp[0] = 1;
        for(int i = 1;i<=A.size();i++)
        {
            if(A[i-1]=='*')
            {
                if(i>1 and A[i-2]=='2')
                    dp[i] = (dp[i-2]*6)%1000000007;
                else if(i>1 and A[i-2]=='1')
                    dp[i] = (dp[i-2]*9)%1000000007;
                else if(i>1 and A[i-2]=='*')
                    dp[i] = (dp[i-2]*15)%1000000007;
                
                dp[i]= (dp[i]+ dp[i-1]*9)%1000000007;
            }
            else if(i>1 and A[i-2]=='*')
            {
                if(A[i-1]<='6')
                    dp[i] = (dp[i]+dp[i-2]*2)%1000000007;
                else
                     dp[i] = (dp[i]+dp[i-2])%1000000007;
                
                if(A[i-1]>='1' and A[i-1]<='9')
                        dp[i] = (dp[i] + dp[i-1])%1000000007; 
                
            }
            else
            {
                if(i>1 and (A[i-2]=='1' or A[i-2]=='2'&& A[i-1]<='6'))
                    dp[i] = (dp[i]+dp[i-2])%1000000007;
            
                if(A[i-1]>='1' and A[i-1]<='9')
                        dp[i] = (dp[i] + dp[i-1])%1000000007;
            }
        }
        return dp[A.size()]%1000000007;
    }
};