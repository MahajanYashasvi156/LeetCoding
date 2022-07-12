class Solution 
{
    vector<string> findsol(int start,string s,unordered_map<string,bool>&dict)
    {
        vector<string> result;
        string word ;
        for(int i = 1;i<21 && start+i<=s.size();i++)
        {
            word = s.substr(start,i);
       
            if(dict.find(word)!=dict.end())
            { 
                if(start+i==s.size())
                     result.push_back(word);
                else
                {
                    auto remaining = findsol(start+i,s,dict);
                     int s= 0;
                     while(s<remaining.size())
                     {
                         result.push_back(word+" "+remaining[s]);
                         s++;
                     }
                }
            }
        }
        return result;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_map<string,bool> dict;
        for(auto w:wordDict)
            dict[w] = true;
        
        return findsol(0,s,dict);
    }
};