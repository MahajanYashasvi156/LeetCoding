//https://leetcode.com/problems/find-the-shortest-superstring/discuss/195290/C%2B%2B-solution-in-less-than-30-lines

class Solution 
{
public:
    string shortestSuperstring(vector<string>& words) 
    {
        int n = words.size();
        vector<vector<int>> overlap(n,vector<int>(n,0));
        vector<vector<string>> dp(1<<n,vector<string>(n));
        
        
        
        //Step 1 :- find the overlap string from i to j. 
        //Maximum size of prefix of j which is suffix of i
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i!=j)
                {
                    for(int k = min(words[i].size(),words[j].size());k>0;k--)
                    {
                        if(words[i].substr(words[i].size()-k)==words[j].substr(0,k))
                        {
                            overlap[i][j] = k;
                            break;
                        }
                    }
                }
            }
        }
        
        //Step2 :- Initialize the DP
        
        for(int i = 0;i<n;i++)
            dp[1<<i][i] +=words[i];
        
        for(int mask = 1;mask<(1<<n);mask++)
        {
            for(int j = 0;j<n;j++)
            {
                if(mask & (1<<j))
                {
                    for(int i = 0;i<n;i++)
                    {
                        if(i!=j and (mask&(1<<i)))
                        {
                            string temp = dp[mask ^ (1<<j)][i] + words[j].substr(overlap[i][j]);
                            
                            if(dp[mask][j].empty() || dp[mask][j].size()>temp.size())
                                dp[mask][j] = temp;
                        }
                    }
                }
            }
        }
        
        int last = (1<<n)-1;
        string result = dp[last][0];
        
        for(int i = 1;i<n;i++)
        {
            if(dp[last][i].size()<result.size())
                result = dp[last][i];
        }
        
        return result;
    }
};