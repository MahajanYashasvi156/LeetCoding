class Solution 
{
    vector<string> findsol(int start,string s,unordered_map<string,bool>&dict,unordered_map<int,vector<string>>&dp)
    {
        vector<string> result;
        string word ;
        for(int i = 0;i<=20 && start+i<s.size();i++)
        {
            word = s.substr(start,i+1);
       
            if(dict.find(word)!=dict.end())
            { 
                if(start+i+1==s.size())
                     result.push_back(word);
                else
                {
                    vector<string> remaining;
                    if(dp.find(start+i+1)!=dp.end())
                         remaining = dp[start+i+1];
                    else
                    {
                         remaining = findsol(start+i+1,s,dict,dp);
                    }
                     int s= 0;
                     while(s<remaining.size())
                     {
                         result.push_back(word+" "+remaining[s]);
                         s++;
                     }
                }
            }
        }
        return dp[start]=result;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_map<string,bool> dict;
        for(auto w:wordDict)
            dict[w] = true;
        
        unordered_map<int,vector<string>>dp;
        return findsol(0,s,dict,dp);
    }
};