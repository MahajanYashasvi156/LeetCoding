class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        unordered_map<char,vector<string>> m;
        
        for(string str: words)
            m[str[0]].push_back(str);
        
        for(int i = 0;i<s.size();i++)
        {
            if(m.find(s[i])!=m.end())
            {
                vector<string> currCharWaiting = m[s[i]];
                
                m.erase(s[i]);
                
                for(string str : currCharWaiting)
                {
                    if(str.size()==1)
                        m['$'].push_back("1");
                    else
                        m[str[1]].push_back(str.substr(1));
                }
            }
        }
        return m['$'].size();
    }
};