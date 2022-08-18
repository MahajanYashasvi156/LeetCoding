class Solution 
{
    int solve(int index,int mask,int tight, string s,vector<vector<vector<int>>>&dp)
    {
        if(index==s.size())
            return mask!=0;
        
        if(dp[index][mask][tight]!=-1)
            return dp[index][mask][tight];
        
        int ub = tight?(s[index]-'0'):9;
        
        int ans = 0;
        
        
        for(int i = 0;i<=ub;i++)
        {
            if(mask & 1<<i)
                continue;
            ans += solve(index+1,(mask==0 and i==0)?mask:mask | 1<<i,tight & (i==ub),s,dp);
        }
       
        return dp[index][mask][tight] = ans;
    }
public:
    int countSpecialNumbers(int n) 
    {
        string s = to_string(n);
        
        vector<vector<vector<int>>>dp(s.size(),vector<vector<int>>(1<<10,vector<int>(2,-1)));
       
        return solve(0,0,1,s,dp);
    }
};