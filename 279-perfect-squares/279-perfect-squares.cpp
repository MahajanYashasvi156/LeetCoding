class Solution {
public:
    int numSquares(int n) 
    {
        vector<int> dp(n+1);
        dp[0]=0;
      
        vector<int> ps;
        for(int i=1;i<=n;i++)
        {
            if(i*i<=n)
                ps.push_back(i*i);
            else
                break;
        }
        
        int count = 0;
        int s = ps.size();
        
        for(int i=1;i<=n;i++)
        {
            int mincount = INT_MAX;
            for(int j=0;j<s;j++)
            {
                if(i-ps[j]>=0)
                    mincount=min(mincount,dp[i-ps[j]]);
            }
            dp[i]=mincount+1;
            cout<<dp[i]<<" ";
        }
        return dp[n];
    }
};