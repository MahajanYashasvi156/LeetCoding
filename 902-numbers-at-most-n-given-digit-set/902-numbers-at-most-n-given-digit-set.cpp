class Solution 
{
    int solve(string &s,int index,int hasStarted,int tight, vector<string>&digits,vector<vector<vector<int>>> &dp)
    {
        if(index==s.size())
            return 1;
        
        if(dp[index][hasStarted][tight]!=-1)
            return dp[index][hasStarted][tight];
        
        int ub = tight ? (s[index]-'0') : stoi(digits[digits.size()-1]);
        
        int ans = 0;
        
        if(hasStarted==0)
            ans +=solve(s,index+1,0,tight and ub== 0, digits,dp);
        for(int i = 0;i<digits.size() and stoi(digits[i])<=ub;i++)
        {
            ans +=solve(s,index+1,1,tight and ub==stoi(digits[i]) , digits,dp);         
        }
        return dp[index][hasStarted][tight] = ans;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) 
    {
        string s = to_string(n);
        
        vector<vector<vector<int>>> dp(s.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        
        return solve(s,0,0,1,digits,dp) - 1;
    }
};