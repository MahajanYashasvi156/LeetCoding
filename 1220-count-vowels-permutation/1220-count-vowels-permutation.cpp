class Solution 
{
public:
    int countVowelPermutation(int n)
    {
        int mod = 1000000007;
        
        vector<int> dp(5,1);
        int a=1,e=1,i=1,o=1,u=1;
        for(int k = 2;k<=n;k++)
        {
            dp[0] = e;
            dp[1] = (a+i)%mod;
            dp[2] = ((a+e)%mod+(o+u)%mod)%mod;
            dp[3] = (i+u)%mod;
            dp[4] = a;
            
            a = dp[0];
            e = dp[1];
            i = dp[2];
            o = dp[3];
            u = dp[4];
        }
        
        return ((a+e)%mod+((i+o)%mod+u)%mod)%mod;
    }
};