class Solution 
{
    int solve(string s, int index, int prevbit,int tight,vector<vector<vector<int>>>&dp)
    {
        if(index==s.size())
            return 1;
        
        if(dp[index][prevbit][tight]!=-1)
           return dp[index][prevbit][tight];
        
        int ub = tight ? (s[index]-'0') : 1;
        
        int ans = 0;
        
        ans = ans + solve(s,index+1,0,tight and ub==0,dp);
            
        if(prevbit==0 and ub==1)
            ans = ans + solve(s,index+1,1,tight and ub==1,dp);
    
        return dp[index][prevbit][tight] = ans;
    }
public:
    int findIntegers(int n) 
    {
        string s ="";
        while(n)
        {
            s = to_string(n%2) + s;
            n = n/2;
        }
     
        vector<vector<vector<int>>> dp(s.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        
        return solve(s,0,0,1,dp);
    }
};