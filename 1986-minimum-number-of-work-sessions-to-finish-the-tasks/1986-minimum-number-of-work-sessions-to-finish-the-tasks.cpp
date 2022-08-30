//qsked in walmart

class Solution 
{
    int solve(vector<int>&tasks,int currentTime, int mask,vector<vector<int>>&dp,int sessionTime)
    {
        if(currentTime>sessionTime)
            return INT_MAX;
        
        if(mask==(1<<tasks.size())-1)
            return 1;
        
        if(dp[currentTime][mask]!=-1)
            return dp[currentTime][mask];
        
        int ans = INT_MAX;
        
        for(int i = 0;i<tasks.size();i++)
        {
            if(mask & 1<<i)
                continue;
            
            int notIncludeInCurrentSession = 1+solve(tasks,tasks[i],mask | (1<<i),dp,sessionTime);
            
            int IncludeInCurrentSession = solve(tasks,currentTime+tasks[i],mask | (1<<i),dp,sessionTime);
            
            ans  = min({ans,notIncludeInCurrentSession,IncludeInCurrentSession});
        }
       
        return dp[currentTime][mask] = ans;
    }
public:
    int minSessions(vector<int>& tasks, int sessionTime) 
    {
        int n = tasks.size();
        vector<vector<int>> dp(sessionTime+1,vector<int>(1<<n,-1));
        return solve(tasks,0,0,dp,sessionTime);
    }
};
