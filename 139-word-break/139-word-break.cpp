class Solution 
{
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_map<string,bool> dict;
        for(auto s:wordDict)
            dict[s] = true;
    
        vector<bool> dp(s.size()+1,false);
       
        dp[0] = 1;
        
        for(int i = 1;i<=s.size();i++) // at i-1 last word ends.
        {
            for(int j = i-1;j>=0 and j>=i-20;j--)//start of the last word.
            {
                if(dp[j] and dict[s.substr(j,i-j)])
                {
                    dp[i] = true;
                    break;
                }   
            }
        }
        return dp[s.size()];
    }
};