class Solution 
{
    int solve(string num,int n,int count,int tight,vector<vector<vector<int>>>&dp)
    {
        if(n==0)
            return count;
    
        if(dp[n][count][tight]!=-1)
            return dp[n][count][tight];
        
        int ub = tight?(num[num.size()-n]-'0'):9;
        
        int ans = 0;
        
        for(int digit = 0;digit<=ub;digit++)
        {
            ans +=solve(num,n-1,count+(digit==1),(tight&(digit==ub)),dp);
            
        }
  
        return dp[n][count][tight] = ans;  
    }
public:
    int countDigitOne(int n)
    {
        string num = to_string(n);
        vector<vector<vector<int>>> dp(num.size()+1,vector<vector<int>>(num.size()+1,vector<int>(2,-1)));
        return solve(num,num.length(),0,1,dp);
    }
};