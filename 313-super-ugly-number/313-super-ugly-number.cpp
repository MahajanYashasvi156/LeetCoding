class Solution 
{
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) 
    {
        vector<long> dp(n,INT_MAX);
        vector<int> index(primes.size(),0);
        dp[0] = 1;

        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<primes.size();j++)
            {
                dp[i] = min(primes[j]*dp[index[j]],dp[i]);
            }
            
            for(int j = 0;j<primes.size();j++)
            {
                if(dp[i]==primes[j]*dp[index[j]])
                    index[j]++;
            }
        }

        return dp[n-1];
    }
};