class Solution {
public:
    int distinctSubseqII(string s) 
    {
        unordered_map<char,int> last;
        
        vector<long>dp(s.size());
        dp[0] = 1;
        last[s[0]] = 0;
        for(int i = 1;i<s.size();i++)
        {
            if(last.find(s[i])!=last.end())    
            {
                dp[i] = 2*dp[i-1]%1000000007;
                if(last[s[i]]>0)
                    dp[i]=(dp[i]-dp[last[s[i]]-1]+1000000007)%1000000007;
            }
            else
                dp[i] = (2*dp[i-1]+1)%1000000007;
            last[s[i]] = i;
        }
        return (dp[s.size()-1]+1000000007)%1000000007;
    }
};