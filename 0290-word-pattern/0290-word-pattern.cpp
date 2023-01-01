class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        unordered_map<char,string>m;
        unordered_map<string,bool>taken;
        int i = 0;
        int j = 0;
        
        while(i<pattern.size())
        {
            if(j>=s.size())
                return false;
            string word = "";
            while(j<s.size() and s[j]!=' ')
            {
                word = word + s[j];
                 j++;
            }
            if(s[j]==' ')
                j++;
            
            if(m.find(pattern[i])!=m.end())
            {
                if(m[pattern[i]]!=word)
                    return false;
            }
            else
            {
                if(taken.find(word)!=taken.end())
                {
                    return false;
                }
                m[pattern[i]] = word;
                taken[word] = true;
            }
            i++;
        }
        return j==s.size();
    }
};