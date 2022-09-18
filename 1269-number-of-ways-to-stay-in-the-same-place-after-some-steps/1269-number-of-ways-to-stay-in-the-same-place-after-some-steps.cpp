class Solution
{
    int solve(int i,int steps,int arrLen,vector<vector<int>> &dp)
    {
        if(steps==0)
            return i==0;
        
        if(dp[i][steps]!=-1)
            return dp[i][steps];
        int ans = 0;
        
        if(i+1<arrLen)
            ans = ans + solve(i+1,steps-1,arrLen,dp);
        
        if(i-1>=0)
            ans = ans + solve(i-1,steps-1,arrLen,dp);
    
        ans = (ans%1000000007 + solve(i,steps-1,arrLen,dp))%1000000007;
        
        return dp[i][steps] = ans;
       
    }
public:
    int numWays(int steps, int arrLen)
    {
        //Atmost we can reach to steps+1 in steps moves by always moving to the right. No need to take arrLen size dp
        vector<vector<int>> dp(steps+1,vector<int>(steps+1,-1));
        
        return solve(0,steps,arrLen,dp);
    }
};