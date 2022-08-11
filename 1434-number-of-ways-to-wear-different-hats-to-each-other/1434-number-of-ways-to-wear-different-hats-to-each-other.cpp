class Solution 
{
    
    int M = 1000000007;
    int solve(int hat,int mask,vector<vector<int>>&hati,vector<vector<int>>&dp,int done,int n)
    {
        if(mask==done)
            return 1;
        
        if(hat>40)
            return 0;
        
        if(dp[hat][mask]!=-1)
            return dp[hat][mask];
       
        int ans = 0;
        ans =solve(hat+1,mask,hati,dp,done,n)%M;
        
        for(int h : hati[hat])
        {
            if(mask & 1<<h)
                continue;
            
            ans = (ans + solve(hat+1,mask | 1<<h,hati,dp,done,n))%M;
        }
        
        return dp[hat][mask] = ans ;
    }
public:
    int numberWays(vector<vector<int>>& hats) 
    {
        int n = hats.size();
        
        vector<vector<int>>dp(41,vector<int>(1<<n,-1));
        
        vector<vector<int>> hati(41);
        
        for(int i = 0;i<n;i++)
        {
            for(int h : hats[i])
                hati[h].push_back(i);
        }
        
        int done = (1<<n)-1;
        
        return solve(1,0,hati,dp,done,n);
    }
};