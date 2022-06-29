class Solution 
{
public:
    int nthUglyNumber(int n) 
    {
        vector<int> dp(n);
    
        dp[0] = 1;

        int i1 = 0;
        int i2 = 0;
        int i3 = 0;

        for(int i = 1;i<n;i++)
        {
            dp[i] = min(2*dp[i1],min(3*dp[i2],5*dp[i3]));
            if(dp[i]==2*dp[i1])
                i1++;
            if(dp[i]==3*dp[i2])
                i2++;
            if(dp[i]==5*dp[i3])
                i3++;
        }
        return dp[n-1];
    }
};