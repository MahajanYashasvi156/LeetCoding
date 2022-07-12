class Solution 
{
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_map<string,bool> dict;
        for(auto s:wordDict)
            dict[s] = true;
    
        vector<bool> dp(s.size(),false);
       
        for(int i = 0;i<s.size();i++)
        {
            for(int j = i;j>=0;j--)
            {
                if(dict[s.substr(0,i+1)] or (dp[j] and dict[s.substr(j+1,i-j)]))
                {
                    dp[i] = true;
                    break;
                }   
            }
        }
        return dp[s.size()-1];
    }
};