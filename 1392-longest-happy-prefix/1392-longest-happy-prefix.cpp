class Solution 
{
public:
    string longestPrefix(string s)
    {
        int i = 1;
        int j = 0;
        vector<int> lps(s.size(),0);
    
        while(i<s.size())
        {
            if(s[i]==s[j])
            {
                lps[i] = j+1;
                j++;
                i++;
            }
            else
            {
               if(j==0)
                   i++;
        
                else
                    j = lps[j-1];
            }
        }
        return s.substr(0,lps[s.size()-1]);
    }
};