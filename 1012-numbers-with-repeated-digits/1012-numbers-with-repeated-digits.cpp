class Solution
{
    int noRepeatation(string &s, int index, bool tight, int mask,vector<vector<vector<int>>>&dp)
    {
        
        if(index==s.size())
            return mask!=0;
        
        if(dp[index][tight][mask]!=-1)
            return dp[index][tight][mask];
        
        int ub = tight?(s[index]-'0'):9;
        
        int ans = 0;
       
        for(int digit = 0;digit<=ub;digit++)
        {
            if(mask==0 and digit==0)
                ans +=noRepeatation(s,index+1,tight and (digit==ub),mask,dp);
            
            else if(mask & (1<<digit))
                continue;
            
            else
                 ans+=noRepeatation(s,index+1,tight and (digit==ub),mask | (1<<digit),dp);
           
        }
        return dp[index][tight][mask] = ans;
    }
public:
    int numDupDigitsAtMostN(int n) 
    {
        string s = to_string(n);
        
        vector<vector<vector<int>>> dp(11,vector<vector<int>>(2,vector<int>(1024,-1)));
        
        return n - noRepeatation(s,0,true,0,dp);
    }
};